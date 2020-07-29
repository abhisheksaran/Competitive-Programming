#include<bits/stdc++.h>
using namespace std;

/*
*@author saran
*@name- 0-1 Knapsack Classic
*@type- DP or Recursive
*@date- 24th July
*/

int solve(int val[], vector< vector<int> > dp,int w[],int i,int Weight){

	if(dp[i][Weight]!=-1) return dp[i][Weight];
	if(Weight<=0) return 0;
	
	if(i==0 && Weight>=w[0]) dp[i][Weight]=val[i];
	else if(i==0) dp[i][Weight]=0; 		
	else
		dp[i][Weight]=max(solve(val,dp,w,i-1,Weight),val[i]+solve(val,dp,w,i-1,Weight-w[i]));


cout<<i<<", "<<Weight<<"= "<<dp[i][Weight]<<"\n";
return dp[i][Weight];
}


int main(){
	int n;
	cin>>n;
	int w[n];
	int val[n];
	for(int i=0;i<n;i++) cin>>val[i];
	for(int i=0;i<n;i++) cin>>w[i];
	
	int Weight;
	cin>>Weight;
	
	//dp[i][j] shows maximum values can be acheived from the set of values of range {0,1,...,i} such that sum of weights of same set is smaller than j
//	int dp[n][Weight+1];
//	memset(dp,-1,sizeof(dp));
	vector<int> z (Weight+1,-1);
	vector< vector<int> > dp(n,z);
		
	int ans=solve(val,dp,w,n-1,Weight);

cout<<ans<<"\n";	

return 0;
}
