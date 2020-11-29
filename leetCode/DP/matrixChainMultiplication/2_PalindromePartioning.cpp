/*
 * @author: saran
 * Input: array size, array 
 * Output: 
 */
#include<bits/stdc++.h>
using namespace std;

bool isPalindrome(string arr, int i, int j){
	while(i<j){
		if(arr[i-1]!=arr[j-1]) return false;
		i++;
		j--;
	}
	return true;	
}

int helper(vector<vector<int>> &dp, string arr, int i, int j){
	if(i==j||i>j||isPalindrome(arr,i,j)) return 0;

	if(dp[i][j] != -1 ) return dp[i][j];
	int mn = INT_MAX;
	for(int k=i;k<j;k++){
		mn = min(mn,helper(dp,arr,i,k)+helper(dp,arr,k+1,j)+1);
	}
	return dp[i][j] = mn;
	
}

int main(){
	int n;
     	string s;
	cin>>s;	
	n = s.length();
	//recursive solution 
	vector<vector<int>> dp(n+1,vector<int> (n+1,-1));
	cout<<helper(dp,s,1,n)<<"\n";

	return 0;
}
