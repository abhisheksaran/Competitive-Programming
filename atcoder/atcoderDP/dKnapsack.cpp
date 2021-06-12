#include<bits/stdc++.h>
using namespace std;
const int INF = (int)1e9;

int n,W;
vector<int > value;
vector<int > weight;
vector<vector<long long int > >dp;
long long int solve (int i, int w){
	if(w <= 0 or i == n) return 0;
	else if(dp[i][w]!=-1) return dp[i][w];
	else {
		dp[i][w] = solve(i + 1, w); // don't take this object!
		if (weight[i] <= w)//we take this object only if possible
			dp[i][w] = max(dp[i][w], (value[i] + solve(i + 1, w - weight[i]))); 	
	}
	return dp[i][w];
}

	
int main(){
	cin>>n>>W;
	value.assign(n,0);
	weight.assign(n,0);
	for(int i=0;i<n;i++) cin>>weight[i]>>value[i];
	dp.assign(n + 1,vector<long long int>(W + 1,-1));
	cout<<solve(0,W);
}
	
