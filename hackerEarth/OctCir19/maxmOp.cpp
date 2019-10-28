#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	long a,b,n;
	unsigned long y;
	long z=(1<<3) -1;
	long ans;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>a>>b>>n;
		int x=n%3;
		if(x==0) {
			y=a^b;
			ans=max(y,~y);}
		else if(x==1) ans=a;
		else ans=b;
		
		cout<<(~y)<<"\n";
		//ans=max(ans,~ans);
		cout<<ans<<"\n";
	}
return 0;
}
