#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,k;
		cin>>n>>k;
		long s=0;
		long l=0;
		int q;
		int j;
		int ans=n+1;
		for( j=0;j<n;j++){
			cin>>q;
			s=s+q;
			l=long(k)*(j+1);
			if(ans==n+1&&s<l) ans=j+1;
		}
		if(ans==n+1) cout<<n+1+((s-l)/k)<<"\n";
		else cout<<ans<<"\n";
	}
return 0;
}
