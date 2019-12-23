#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
for(int i=0;i<t;i++){
	int r,l;
	int n;
	cin>>l>>r;
	long ans=0;
	int a;
	int d=4;
	if(l==1) {
		ans=-2;
		l=3;
	}
	if(l==2){
		ans=-1;
		l=3;
	}
	
	if(l%2==1&&r%2==0) {
		n=r-l+1;
		n/=2;
		a=(l-1)*2;
		ans+=((2*a+(n-1)*d)*n)/2;
	}
	else if(l%2==0&&r%2==0) {
		n=r-(l+1)+1;
		n/=2;	
		a=l*2;
		ans+=(l-2);
		ans+=((2*a+(n-1)*d)*n)/2;
	}
	
	else if(l%2==1&&r%2==1) {
		n=r-1-l+1;
		n/=2;
		a=(l-1)*2;
		ans+=(r-1);
		ans+=((2*a+(n-1)*d)*n)/2;
	}
		
	else if(l%2==0&&r%2==1) {
		n=r-1-(l+1)+1;
		n/=2;
		a=l*2;
		ans+=(r-1)+(l-2);
		ans+=((2*a+(n-1)*d)*n)/2;
	}
		
	cout<<ans<<"\n";

	for(int j=2;j<=30;j++){
		int k=1;
		k=k<<j;
//		cout<<k<<"\n";
		if(k>r) break;
		if(k>=l&&k<=r) 
		{	ans-=(k-1);
			
	//	cout<<k<<"\n";
		}
	}
 	cout<<ans<<"\n";

}
return 0;
} 
