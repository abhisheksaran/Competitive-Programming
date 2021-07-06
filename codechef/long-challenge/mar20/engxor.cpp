#include<bits/stdc++.h>
using namespace std;

int setBit(int x){
	if(x==0) return 0;
	return (x&1)+setBit(x>>1);
}

int main(){
	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,q,even_n,odd_n,Q;
		even_n=0;
		odd_n=0;
		cin>>n>>q;
		vector<int> a(n);
		for(int j=0;j<n;j++) cin>>a[j];
		for(int j=0;j<n;j++) {
			if(setBit(a[j])&1) odd_n++;
			else even_n++; 
		}
	
		for(int j=0;j<q;j++) {
			cin>>Q;
			if((setBit(Q)&1)==0) cout<<even_n<<" "<<odd_n<<"\n";
			else cout<<odd_n<<" "<<even_n<<"\n";
		}

	}	

return 0;
}
