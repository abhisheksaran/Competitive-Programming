/*
 * @author: saran
 * Input: string a, string b 
 * Output: Output the length of longest common subsequence
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	string a,b;
	cin>>a>>b;

	//top down dp
	vector<vector<int>> dp2 (a.length()+1, vector<int> (b.length()+1,-1));
	//memset(&dp,-1,sizeof(dp));
	//dp.assign(dp.size(),-1);
	//base case
	for(int i=0;i<=a.length();i++) dp2[i][0] = 0;
	for(int i=0;i<=b.length();i++) dp2[0][i] = 0;
	//iterative dp
	int result = 0;
	for(int i=1;i<=a.length();i++){
		for(int j=1;j<=b.length();j++){
			if(a[i-1]==b[j-1]) dp2[i][j] = 1+ dp2[i-1][j-1];
			else dp2[i][j] = 0;
			//cout<<i<<" "<<j<<" "<<dp2[i][j]<<"\n";
			result = max(result, dp2[i][j]);
		}
	}
	cout<<result<<"\n";

	return 0;
}
