/*
 * @author: saran
 * Input: string a
 * Output: Find longest repeating subsequence of teh string
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	string a,b;
	cin>>a;
	b=a;
	int n= a.length();
	vector<vector<int>> dp(n+1,vector<int>(n+1,0));

	for(int i=1;i<=n;i++){
		for(int j=0;j<=n;j++){
			if(a[i-1]==b[j-1]&&i!=j){
				dp[i][j]= 1+ dp[i-1][j-1];
			}
			else{
				dp[i][j] = max(dp[i][j-1],dp[i-1][j]);
			}
		}
	}
	cout<<dp[n][n]<<"\n";
	return 0;
}
