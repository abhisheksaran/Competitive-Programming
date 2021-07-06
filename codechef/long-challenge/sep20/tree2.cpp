#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int a[n];
		for(int j=0;j<n;j++) cin>>a[j];
		sort(a,a+n);
		int ans=0;
		int j=0;
		while(j<n&&a[j]==0) j++;
		
		for(j;j<n;j++){
			if(j>0&&a[j]==a[j-1]) continue;
			ans++;		
		}
		cout<<ans<<"\n";
	}

return 0;
}
