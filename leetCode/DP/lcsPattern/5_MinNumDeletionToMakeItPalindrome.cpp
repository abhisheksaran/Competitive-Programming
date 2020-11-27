/*
 * @author: saran
 * Input: string a
 * Output: Find the minm number of deletion to make it a palindrome 
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	string a;
	cin>>a;
	int n=a.length();
	string b=a;
	reverse(b.begin(),b.end());
	cout<<a<<" "<<b<<"\n";
	//longest palindromic subseq will be lcs of a and its reverse string 
	//that seq will be the palindrome we want to make
	vector<vector<int>> dp (n+1, vector<int> (n+1,0));
	for(int i=1 ;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i-1]==b[j-1]) dp[i][j]=1+dp[i-1][j-1];
			else{
				dp[i][j]= max(dp[i-1][j], dp[i][j-1]);
			}
		}
	}
	cout<<n-dp[n][n]<<"\n";
	return 0;
}
/*
 * Hint:
 * the minimum number of deletion means the maximum length palindrome subsequence possible of the input string.
 * Our answer would be length of string - length of maximum palindromic subsequence of the string 
 */
