/*
 * @author: saran
 * Input: array size, array 
 * Output: if array can be partitioned in equal sums of subarrays or not. If yes, print yes else print no.
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> arr;
	int sum = 0;
     	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		sum+=x;
	       	arr.push_back(x);	
	}
	
	if(sum%2==1) {
		cout<<"Noo\n";
		return 1;
	}
	else sum = sum/2;

	//iterative dp
	vector<vector<bool>>  dp(n+1, vector<bool> (sum+1, false));

	//base case
	for(int j=0;j<=sum;j++) dp[0][j] = false; 
	for(int i=0;i<=n;i++) dp[i][0] = true;

	for(int i=1; i<=n ;i++){
		for(int j=1;j<=sum;j++){
			if(arr[i-1]>j) dp[i][j] = dp[i-1][j];
			else dp[i][j] = dp[i-1][j] or dp [i-1][j-arr[i-1]] ;
		}
	}

	if(dp[n][sum]) cout<<"Yes\n";
	else cout<<"No\n";
	return 0;
}
