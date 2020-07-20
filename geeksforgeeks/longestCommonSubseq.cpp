#include<bits/stdc++.h>
using namespace std;

/*
*@author saran
*@name Longest Common Subsequence
*@type DP
*/

int main(){

string s1,s2;
cin>>s1>>s2;

int n=s1.size();
int m=s2.size();

int ans[n][m]={0};


for(int i=0;i<n;i++){
	for(int j=0;j<m;j++){
		
		if(s1[i]==s2[j]) {
			if(i==0&&j==0) ans[i][j]=1;
			else if (i==0) ans[i][j]=max(1,ans[i][j-1]);
			else if (j==0) ans[i][j]=max(1,ans[i-1][j]);
			else ans[i][j]=ans[i-1][j-1]+1;
		}
		else{
			if(i==0&&j==0) ans[i][j]=0;
			else if (i==0) ans[i][j]=max(0,ans[i][j-1]);
			else if (j==0) ans[i][j]=max(0,ans[i-1][j]);
			else ans[i][j]=max(ans[i-1][j],ans[i][j-1]);
		}	
	}
}

cout<< ans[n-1][m-1]<<"\n";

return 0;
}
