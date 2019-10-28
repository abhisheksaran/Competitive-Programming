#include<bits/stdc++.h>
using namespace std;

int fact( int n){
	if(n==1) return 1;
	else return n*fact(n-1);
}

int main(){
	int t,n;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n;
		int ans=((n*n-n)/2)*fact(n);
		cout<<ans<<"\n";
	}
	return 0;
}
