#include<bits/stdc++.h>
using namespace std;
int n,k;
int m=int(1e9)+7;
vector<int> a;
int x=0;
vector<vector< int> > dp;
/*
int solve(int i,int k){
	x++;
	cout<<x<<"\n";
	if(i==n-1||k==0){
		if(k>a[i]) dp[i][k]=0;
		else dp[i][k]=1;
	}
	else if(dp[i][k]!=-1) return dp[i][k];
	else {
		dp[i][k]=0;
		for(int j=0;j<=a[i];j++){
			if(k-j<0) break;
			dp[i][k]=(dp[i][k]%m+solve(i+1,k-j)%m) %m;
		}
	}
//	cout<<i<<" "<<k<<" "<<dp[i][k]<<"\n";
	return dp[i][k];
}
*/
int main(){
	cin>>n>>k;
	a.assign(n,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	dp.assign(n+1,vector<int> (k+1,-1));
	vector<int> sum;
	sum.assign(k+1,0);
	dp[0][0]=1;
	for(int i=0;i<n;i++){
		for(int j=0;j<=k;j++) sum[j]=(sum[j-1]+dp[i-1][j-1])%m;
		//sum[j]=dp[i-1][j-1] + ... + dp[i-1][0];
		for(int j=0;j<=k;j++)
			dp[i][j]=(sum[j]-sum[max(0,j-a[i])]+dp[i-1][j])%m;
	cout<<dp[n][k];
	return 1;
}



	
//understand the concept!!
//https://atcoder.jp/contests/dp/submissions/6106185
//




