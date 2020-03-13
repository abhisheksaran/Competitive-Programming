#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector< int> c(n);
	for (int i=0;i<n;i++) cin>>c[i];
	int ans=0;
	int even=0;
	int odd=0;
	for (int i=0;i<n;i++) {
		if(c[i]%2==0) {
			ans+=even+1;
			even++;
		}
		else
		{
			ans+=odd;
			odd++;
		}
			
	}
	cout<<ans<<"\n";
return 0;
}
	
	
