/*
 * @author: saran
 * Input: array size, array 
 * Output: 
 */
#include<bits/stdc++.h>
using namespace std;

int helper(vector<vector<int>>& dp, vector<int> arr, int i, int j){
	if(i==j||i>j) return 0;

	if(dp[i][j]!=-1) return dp[i][j] ;
	int mn = INT_MAX;
	for(int k=i;k<j;k++){
		mn = min(mn,helper(dp,arr,i,k)+helper(dp,arr,k+1,j)+(arr[i-1]*arr[j-1]*arr[k]));
	}
	return dp[i][j] = mn;
	
}
int main(){
	int n;
	cin>>n;
	vector<int> arr;
     	for(int i=0;i<n;i++){
		int x;
		cin>>x;
	       	arr.push_back(x);	
	}

	//recursive solution
	vector<vector<int>> dp(n+1, vector<int> (n+1,-1)); 
			
	cout<<helper(dp,arr,1,n)<<"\n";

	return 0;
}
