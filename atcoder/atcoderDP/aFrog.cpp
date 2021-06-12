#include<bits/stdc++.h>
using namespace std;
int n;
vector<int > h;
vector<long> cost;


long solve(int i){
	if(i==0){
		cost[i]=0;
		return cost[i];
	}
	else if(i==1){
		cost[i]=abs(h[1]-h[0]);
	}
	else if(cost[i]!=-1)
		return cost[i];
	else{
		cost[i]=min(abs(h[i-1]-h[i])+solve(i-1),(abs(h[i-2]-h[i])+solve(i-2)));
		return cost[i];
	}

}


	
int main(){
	cin>>n;
	h.assign(n,0);
	for(int i=0;i<n;i++){
		cin>>h[i];
	}
	cost.assign(n,-1);
	cout<<solve(n-1);
	return 0;
}

