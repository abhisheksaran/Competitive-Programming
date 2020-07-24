#include<bits/stdc++.h>
using namespace std;

/*
*@author saran
*@name- Given a set of non-negative integers, and a value sum, determine if there is a subset of the given set with sum equal to given sum.
*@type- DP
*@date-21th July
*/

int main(){
	int n;
	cin>>n;
	int arr[n];	
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum=arr[i]+sum;	
	}
	int desiredSum;
	cin>>desiredSum;


	//true iff using first i values sum j can be obtained
	bool dp[n+1][sum+1]={false};

	for(int i=0;i<=sum;i++) dp[0][i]=false;
	for(int i=0;i<=n+1;i++) dp[i][0]=true;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(j>=arr[i-1]) dp[i][j]=dp[i-1][j-arr[i-1]];//include
			dp[i][j]= dp[i-1][j]||dp[i][j];//not include current value
		}
	
	}	
	if(dp[n][desiredSum]==true)
		cout<<"YES\n";	
	else cout<<"NO\n";

return 0;
}
