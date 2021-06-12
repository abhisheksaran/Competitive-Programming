#include<bits/stdc++.h>

using namespace std;
const long INF=(long) 1e17;
vector<long> a;
vector<vector<long>> dp;
vector<vector<long>> sum;

int main(){
	int n,idx,i,j;
	cin>>n;
	a.assign(n+1,0);
	dp.assign(n+1,vector<long> (n+1,-1));	
	sum.assign(n+1,vector<long> (n+1,0));
	//dp[i][j] is minm cost of combining intervel i,j
	for( i=0;i<n;i++) cin>>a[i];
	for(i=n-1;i>=0;i--){
		for(j=i;j<n;j++){
			if(i==j) {
				sum[i][j]=a[i];
				dp[i][j]=0;
			}
			else if(j==i+1) {
				sum[i][j]=sum[i][j-1]+a[j];
				dp[i][j]=sum[i][j];
			}
			else { 
			  sum[i][j]=sum[i][j-1]+a[j];
			  long minm=INF;
			 
			  for(int y=i;y<j;y++){
				  minm=min(minm,dp[i][y]+dp[y+1][j]);
			//:	 dp[i][j]=sum[i][j]+min(dp[i][j-1],dp[i][j-2]+dp[j-1][j]);
			  }
			  dp[i][j]=sum[i][j]+minm;

			}
			//:cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
		}
	}
	cout<<dp[0][n-1];




	return 0;
}

