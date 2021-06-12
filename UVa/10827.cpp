#include<bits/stdc++.h>
using namespace std;
const int INF=-1280000;

//kadane algo finds maxm sum contagous subarray
//idea is look towards all positive sum subarray and keep track of a maxm so far contaguoussubarray among all positive segments
//each time we get a positve sum we compare it with max_So_far and update max_so_far if its greater than max_So_far 
int kadane(int arr[],int n){
	int max_so_far=INF;
	int sum=0;
	for(int j=0;j<2*n-2;j++){
		int i=j%n;
		sum+=arr[i];
		if(sum>max_so_far)	max_so_far=sum;
		if(sum<0) sum=0;
		if(sum==0&&j>n-1) break;
	}
	return max_so_far;
}
		
int main()
{
	int n;
	cin>>n;

	int arr[n][n];
	int dp[n][n][n][n];
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cin>>arr[i][j];
			dp[i][i][j][j]=arr[i][j];//base  case

		}
	}
	//calculating 1d sum per column and row
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=j+1;k<n;k++){
				dp[i][i][j][k]=dp[i][i][j][k-1]+arr[i][k];
				dp[j][k][i][i]=dp[j][k-1][i][i]+arr[k][i];
			}
		}
	}
	//fixing row from i to j
	//k is iterating over row
	//temp i is storing colmn i sum from row i to j
	//when you give such input temp arr to kadane algo
	//what it finally gives you is a max sum submatrix over all possible  contaguous sumatrixs of row i and j
	int maxx=INF;
	for(int i=0;i<n;i++){
		for(int j=i;j<n;j++){
			int temp[n];
			for(int k=0;k<n;k++){
				temp[k]=dp[i][j][k][k];
				
			}

			maxx=max(maxx,kadane(temp,n));
		}
	}

	cout<<maxx<<"\n";
	return 0;
}

