#include<bits/stdc++.h>
using namespace std;
int main(){
int t;
cin>>t;
for(int i=0;i<t;i++){
	int j,n;
	cin>>n;
	vector<int > in(n,0);
	for(j=0;j<n;j++) cin>>in[j];
	int lastind =-6;
	
	for(j=0;j<n;j++){
		if(in[j]==1) {
			if(j-lastind <6 ){
				cout<<"NO\n";
				break;
			}
			lastind=j;
		}
	
	}
	if(j==n) cout<<"YES\n";
	
}


return 0;
}
