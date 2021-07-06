#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0; i<t; i++){
		int n,m;
		cin>>n>>m;
		vector<int> a(n,0);
		vector<int> b(m,0);
		int sa =0;
		for(int j = 0; j<n; j++){
			cin>>a[j];
			sa += a[j];
		}
		int sb = 0;
		for(int j = 0; j<m; j++){
			cin>>b[j];
			sb += b[j];
		}
		int d = sa-sb;
		if(d>0){
		       	cout<<0<<"\n";
			continue;
		}
		sort(a.begin(), a.end());
		sort(b.begin(), b.end(), greater<int>());
		
		int u = 0;
	
		while(u<n && u <m){
			d += (b[u] - a[u])*2;
		
			if(d>0){
				cout<<u+1<<"\n";
				break;
			}
			u++;

		}
		if(u==n||u==m) cout<<-1<<"\n";
	}

	return 0;
}
