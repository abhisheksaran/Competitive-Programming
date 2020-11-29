/*
 * @author: saran
 * Input: array size, array, sum 
 * Output: count the number of subsets of given sum
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> arr;
     	for(int i=0;i<n;i++){
		int x;
		cin>>x;
	       	arr.push_back(x);	
	}
	int sum;
	cin>>sum;

	//iterative dp
	vector<vector<int>>  dp(n+1, vector<int> (sum+1, 0));

	//base case
	for(int j=0;j<=sum;j++) dp[0][j] = 0; 
	for(int i=0;i<=n;i++) dp[i][0] = 1;

	for(int i=1; i<=n ;i++){
		for(int j=1;j<=sum;j++){
			if(arr[i-1]>j) dp[i][j] = dp[i-1][j];
			else dp[i][j] = dp[i-1][j] + dp [i-1][j-arr[i-1]] ;
		}
	}

	cout<<dp[n][sum]<<"\n";
	return 0;
}
