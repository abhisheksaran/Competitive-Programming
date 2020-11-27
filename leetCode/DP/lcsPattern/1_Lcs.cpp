/*
 * @author: saran
 * Input: string a, string b 
 * Output: Output the length of longest common subsequence
 */
#include<bits/stdc++.h>
using namespace std;

int helperRec(string a, string b,int i, int j){
	//base condition
	if(i==0||j==0) return 0;

	//choice diagram and making smaller calls
	if(a[i-1]==b[j-1]) return 1+helperRec(a,b,i-1,j-1);
	else return max(helperRec(a,b,i-1,j),helperRec(a,b,i,j-1));
}

int helperRecMemo(string a, string b, int i, int j, vector<vector<int>> &dp){
	//base condition
	if(i==0||j==0) return 0;

	//using memoization
	if(dp[i][j]!=-1) return dp[i][j] ;
	//choice diagram and making smaller calls
	if(a[i-1]==b[j-1]) return dp[i][j] = 1+helperRec(a,b,i-1,j-1);
	else return dp[i][j] = max(helperRec(a,b,i-1,j),helperRec(a,b,i,j-1));

}

int main(){
	string a,b;
	cin>>a>>b;

	//recursive approach 
	//if(a[i]==b[j] lcs(a,b ,i ,j)= 1+lcs(a,b,i-1,j-1);
	//else lcs(a, b, i ,j) = max(lcs(a, b, i-1, j), lcs(a, b, i, j-1));
	cout<<helperRec(a,b,a.length(),b.length())<<"\n";
	
	//memoization
	//i and j are changing
	//store the value of a lcs (i,j) somewhere
	vector<vector<int>> dp (a.length()+1, vector<int> (b.length()+1,-1));
	cout<<helperRecMemo(a,b,a.length(),b.length(),dp)<<"\n";
	
	//top down dp
	vector<vector<int>> dp2 (a.length()+1, vector<int> (b.length()+1,-1));
	//memset(&dp,-1,sizeof(dp));
	//dp.assign(dp.size(),-1);
	//base case
	for(int i=0;i<=a.length();i++) dp2[i][0] = 0;
	for(int i=0;i<=b.length();i++) dp2[0][i] = 0;
	//iterative dp
	for(int i=1;i<=a.length();i++){
		for(int j=1;j<=b.length();j++){
			if(a[i-1]==b[j-1]) dp2[i][j] = 1+ dp2[i-1][j-1];
			else dp2[i][j] = max(dp2[i-1][j], dp2[i][j-1]);
		}
	}
	cout<<dp2[a.length()][b.length()]<<"\n";
	
	//print lcs
	string lcs;
	int i = a.length();
	int j = b.length();
	while(i>0&&j>0){
		if(a[i-1]==b[j-1]){
			lcs.push_back(a[i-1]);
			i--;
			j--;
		}
		else if(dp2[i-1][j]>dp2[i][j-1]) i--;
		else j--;
	}
	reverse(lcs.begin(),lcs.end());	
	cout<<"LCS is: "<<lcs<<"\n";
	return 0;
}
