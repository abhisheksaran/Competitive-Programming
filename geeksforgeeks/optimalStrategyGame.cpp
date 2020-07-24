#include<bits/stdc++.h>
using namespace std;

/*
*@author saran
*@name- 
*@type-
*@date-
*/

//dp[i][j] is maximum scores can be obrained from pile i to pile j by first player(  0<=i,j<=n-1  )

int maxx=100;
int dp[100][100];

//solve returns maxm score by first player in range[i,j] , sum is sum of elements in same range
int solve(int arr[],int i,int j, int sum){

	if(dp[i][j]!=-1) return dp[i][j];	
	
	if(i==j-1) dp[i][j]=max(arr[i],arr[j]);

	//max in this range is equal to max of  total sum in this range - optimal value in next turn 	
	else dp[i][j]=max((sum-solve(arr,i+1,j,sum-arr[i])),(sum-solve(arr,i,j-1,sum-arr[j])));

cout<<i<<", "<<j<<" ="<<dp[i][j]<<"\n";
 return dp[i][j];
} 

int main(){
	int n;
	cin>>n;
	int arr[n];
	int sum=0;
	for(int i=0;i<n;i++){
		cin>>arr[i];
		sum+=arr[i];
	}
	memset(dp,-1,sizeof(dp));
	int ans=solve(arr,0,n-1,sum);	
	cout<<ans<<"\n";

return 0;
}
