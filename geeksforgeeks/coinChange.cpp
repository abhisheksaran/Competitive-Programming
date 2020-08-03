#include<bits/stdc++.h>
using namespace std;

/*
*@author saran
*@name- Given a value N, if we want to make change for N cents, and we have infinite supply of each of S = { S1, S2, .. , Sm} valued coins, how many ways can we make the change? The order of coins doesn’t matter(Geeks For Geeks).
*@type- DP
*@date- 29th July
*/

int main(){

	int n;
	cin>>n;
	int m;
	cin>>m;
	int arr[m+1];
	for(int i=1;i<=m;i++) cin>>arr[i];
/*	
	//a[i][j] represents the number of ways coin collection for value i using coins number 1,2,...j
	int a[n+1][m+1];
	
	//intialization
	memset(a,0,sizeof(a));	
	int i,j;
	for(i=0;i<=n;i++){
		for( j=1;j<=m;j++){
			if(i==0) a[i][j]=1;
			else if(i>=arr[j]) a[i][j]=a[i-arr[j]][j]+a[i][j-1];
			else a[i][j]=a[i][j-1];
			cout<<i<<" "<<j<<" ="<<a[i][j]<<"\n";
		}
	}
			

		
	cout<<a[n][m]<<"\n";
*/

	//simple method
	//dp[i] stores number of ways of coin collection of value i
	int dp[n+1]={0};
	dp[0]=1;
	for(int i=1;i<=m;i++){
		for(int j=arr[i];j<=n;j++){
			dp[j]+=dp[j-arr[i]];
		}
	}
	cout<<dp[n]<<"\n";
return 0;
}
