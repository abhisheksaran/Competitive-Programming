#include<bits/stdc++.h>
using namespace std;

/*
*@author saran
*@name- 
*@type-
*@date-
*/

int main(){
	int t,n;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		int arr[n];
		for(int j=0;j<n;j++){
			cin>>arr[j];
		}				
		
		//dp[i] is 1 if one who starts from ith pile wins the game
		int dp[n+1];
		
		//intialization
		dp[n]=1;
		
//		cout<<dp[n]<<" ";
		for(int j=n-1;j>=1;j--){
			if(arr[j-1]==1) dp[j]=abs(1-dp[j+1]);
			else dp[j]=1;
//			cout<<dp[j]<<" ";
		}
		
		if(dp[1]==1) cout<<"First\n";
		else cout<<"Second\n";

	}	

return 0;
}
