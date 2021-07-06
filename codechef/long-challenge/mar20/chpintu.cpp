#include<bits/stdc++.h>
using namespace std;
#define c 10000
int main(){
	
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,m;
		cin>>n>>m;
		vector<int> f_type(n);
		vector<int> cost(m,c);
		for(int j=0;j<n;j++) cin>>f_type[j];
		for(int j=0;j<n;j++) {
			int x;
			cin>>x;
			if(cost[f_type[j]-1]==c) cost[f_type[j]-1] = x;
			else cost[f_type[j]-1]+=x;
		}
		sort(cost.begin(),cost.end());
	cout<<cost[0]<<"\n";
		
	}

	return 0;
}
