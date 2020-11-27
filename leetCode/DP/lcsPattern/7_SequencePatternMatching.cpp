/*
 * @author: saran
 * Input: string a, string b 
 * Output: true if a is subseq of b else false
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	string a,b;
	cin>>a>>b;

	int n = a.length();
	int m = b.length();

	vector<vector<int>> dp(n+1, vector<int> (m+1,0));

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(a[i-1]==b[j-1]){
				dp[i][j] = 1+dp[i-1][j-1];
			}
			else dp[i][j] = max(dp[i-1][j], dp [i][j-1]);
		}
	}
	cout<<dp[n][m]<<"\n";
	if(dp[n][m] == n ) cout<<"True\n";
	else cout<<"False\n";
	return 0;
}
