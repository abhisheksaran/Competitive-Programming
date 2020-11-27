/*
 * @author: saran
 * Input: string a 
 * Output: Output the minimum number of insertion in the string to needed to make it a palindrome
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	string a,b;
	cin>>a;
	b=a;
	reverse(b.begin(),b.end());
	int n = a.length();
	vector<vector<int>> dp (n+1, vector<int>(n+1,0));

	for(int i=1;i<=n;i++){
		for(int j=1;j<=n;j++){
			if(a[i-1]==b[j-1]) dp[i][j] = 1+ dp[i-1][j-1];
			else dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
		}
	}
	
	cout<<n-dp[n][n]<<"\n";
	return 0;
}
/*
 * get the lcs of string and its reverse
 * the number of insertion will be the size of string - lcs
 */ 
