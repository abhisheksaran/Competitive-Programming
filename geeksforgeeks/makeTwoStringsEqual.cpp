#include<bits/stdc++.h>
using namespace std;

/*
*@author saran
*@name 
*@type
*/

int main(){

	string s1,s2;
	cin>>s1>>s2;
	
	int m=s1.size();
	int n=s2.size();
	
	//dp[i][j] is optimum cost of substrings of string 1 and 2 of sizes i and j respectively
	int dp[m+1][n+1];

	for(int i=0;i<=m;i++){
		for(int j=0;j<=n;j++){
			// base case.
			cout<<"_____________________________________________i="<<i<<", j="<<j<<"______________________________________________________________\n";
			if(i==0||j==0) {
				cout<<"case 1: either i or j is 0\n";
				dp[i][j]=i+j;//either delete whole or insert whole	
			}
			else if(s1[i-1]==s2[j-1]){
				cout<<"case 2: last character of both the strings is equal\n";
				dp[i][j]=dp[i-1][j-1];	
			}		
			else {
				cout<<"case 3: min of 1+ ("<<dp[i][j-1]<<"<insert on last char>, "<<dp[i-1][j]<<"<delete the last char>, "<<dp[i-1][j-1]<<"<replace the last char>"<<")\n";
				dp[i][j]=1+min(dp[i][j-1],min(dp[i-1][j],dp[i-1][j-1]));//1+ min( insert,delete or replace on last character of s1)
			}	
			cout<<"cost of string "<<s1.substr(0,i)<<" and "<<s2.substr(0,j)<<" is="<<dp[i][j]<<"\n\n";
		}
	}
	cout<<"_________________________________Final answer is="<<dp[m][n]<<"___________________________________________\n";

return 0;
}
