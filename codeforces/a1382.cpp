#include<bits/stdc++.h>
using namespace std;

/*
*@author saran
*@name- 
*@type-
*@date-
*/

int main(){
int t;
cin>>t;
for(int i=0;i<t;i++){
	int n,m;
	cin>>n>>m;
	int ans=-1;
	int arr[1001]={0};
	for(int i=0;i<n;i++) {
		int a;
		cin>>a;
		arr[a]=1;
	}
	for(int i=0;i<m;i++){
		int a;
		cin>>a;
		if(arr[a]==1) ans=a; 
	}
	if(ans!=-1){
		cout<<"YES\n";
		cout<<"1 "<<ans<<"\n";
	}
	else cout<<"NO\n";
	
	
}

return 0;
}
