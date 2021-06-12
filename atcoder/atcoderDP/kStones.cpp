#include<bits/stdc++.h>
using namespace std;
int n,k;
vector<int> a;
vector<int > dp;
// run time error
int solve(int score){
	if(score<a[0]) dp[score]=0;
	else if(dp[score]!=-1) return dp[score];
	else{	
		for(int i=n-1;i>=0;i--){
			//score>=a[i] condition is important
			if(score>=a[i]&&solve(score-a[i])==0){dp[score]=1;return dp[score];}
		}
		dp[score]=0;
	}
	return dp[score];
}
	
		
int main(){
	cin >>n>>k;
	dp.assign(k+1,-1);
	a.assign(n,0);
	for(int i=0;i<n;i++) cin>>a[i];

	for(int i=n-1;i>=0;i--){
		if(solve(k-a[i])==0){
			cout<<"First";
			return 0;
		}
	}
	cout<<"Second";
	return 0;
	

/*	for(int i=1;i<=k;i++){
		for(int j=0;j<n;j++){
			if(i-a[j]&&dp[i-a[j]*/
}


