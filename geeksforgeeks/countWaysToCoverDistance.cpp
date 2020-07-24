#include<bits/stdc++.h>
using namespace std;

/*
*@author saran
*@name- Given a distance ‘dist, count total number of ways to cover the distance with 1, 2 and 3 steps
*@type- DP
*@date-	21th July 
*/

int main(){

	int d;
	cin>>d;
	//dp[i] counts number of ways distance i can be ocvered if allowed steps are of  distance 1 or 2 or 3
	int dp[d+1];	
	//base cases
	dp[0]=0;
	dp[1]=1;
	dp[2]=2;
	dp[3]=4;
	//dp
	for(int i=4;i<=d;i++){

		dp[i]=dp[i-1]+dp[i-2]+dp[i-3];
	
	}
	
	cout<<"The number of ways distance "<<d<<" can be covered="<<dp[d]<<"\n";

return 0;
}
