#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i< t;i++){
		int n;
		cin >>n;
		int a[n][n];	
		for(int j=0;j<n;j++) {
			for(int k=0;k<n;k++) cin>>a[j][k];
		}
		int j=n-1;
		int check=0;
		int ans=0;
		while(j>0){
//			cout<<check<<"\n";
			if(check==0){
				if(a[0][j]!=j+1) {
					ans++;
					check=1;
				}
			}
			else {
//				cout<<j<<" "<<a[0][j]<<"\n";
				if(a[0][j]==j+1) {
					ans++;
					check=0;
				}
			}
			j--;
		}
		cout<<ans<<"\n";
	}
	
	return 0;

}
