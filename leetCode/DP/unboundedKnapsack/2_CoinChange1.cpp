/*
 * @author: saran
 * Input: array size, array of coins, sum
 * Output: how many ways you can get the given sum using given  coins 
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

	//recursion 
	//sum==0 return 1
	//n==0 or sum<0 return 0;
	//coinChange(sum,n)=coinChange(sum-arr[n-1],n)+coinChange(sum, n-1)
	//unbounded knapsack becuase we can take same coin mulitple times
	
	//iterative dp of unbounded knapsack 
	vector<vector<int> > dp (n+1,vector<int>(sum+1));

	//base 
	for(int j=0;j<=sum;j++) dp[0][j] = 0;
	for(int i=0;i<=n;i++) dp[i][0] = 1;

	for (int i=1;i<=n;i++){
		for(int j=0;j<=sum;j++){
			if (j<arr[i-1]) dp[i][j] = dp[i-1][j];
			else dp[i][j] =( dp[i-1][j]+ dp[i][j-arr[i-1]]);
		}
	}
	cout<<dp[n][sum]<<"\n";
	return 0;
}
