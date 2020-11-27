/*
 * @author: saran
 * Input: string a, string b 
 * Output: 
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	string a,b;
	cin>>a>>b;
	int n = a.length();
	int m = b.length();

	vector<vector<int>> dp(n+1, vector<int>(m+1,0));
	for(int i=0;i<=n;i++){
		for(int j=0;j<=m;j++){
			//base condition
			if(i==0) dp [i][j]=j;
			else if(j==0) dp [i][j]=i;	
			else if(a[i-1]==b[j-1]) dp[i][j] = dp[i-1][j-1];
			//either you delete the curr ele from a or you insert an ele same as last ele of b 
			else{
				dp[i][j] = 1+ max(dp[i-1][j],dp[i][j-1]);
			}
		

		}
	}
	cout<<dp[n][m]<<"\n";
	int insertion=0;
	int deletion=0;
	int i=n;
	int j=m;
	while(i>0&&j>0){
		if(a[i-1]==b[j-1]){
			i--;
			j--;
		}
		else if(dp[i-1][j]>dp[i][j-1]){
			j--;
			insertion++;
		}
		else{
			deletion++;
			i--;
		}
	}	
	if(i>0) deletion+=i;
	if(j>0) insertion+=j;
	cout<<"Insertion: "<<insertion<<"\n";
	cout<<"Deletion: "<<deletion<<"\n";
	return 0;
}
