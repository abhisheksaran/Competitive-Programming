#include<bits/stdc++.h>
using namespace std;
int n;
const long long INF=int(1e13);
vector<int> a;
vector< vector <long long > > dp;
// dp[i][j] maximizes scores of player  A in range i[,j] which is=( current run of player A- player B's max run in modified new range) because each player play optimally and try to win
// 
long long solve(int i,int j){
	if(i==j) return a[i];
	else if(dp[i][j]!=INF) return dp[i][j];
	else{ // taro tries to maximize x-y while jiro tries to maximize y-x
		dp[i][j]=max(a[i]-solve(i+1,j),a[j]-solve(i,j-1));
	}
	//cout<<i<<" " <<j<<" "<<dp[i][j]<<"\n";
	return dp[i][j];
	
}
int main(){
	cin>>n;
	a.assign(n,0);
	for(int i=0;i<n;i++) cin>>a[i];
	dp.assign(n,vector<long long> (n,INF));

	cout<<solve(0,n-1);
	return 0;

}




	







