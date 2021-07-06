#include<bits/stdc++.h>
using namespace std;

bool helper(int n, int k, int x, int y, int s){
	
	if(x==s) return false;
	if(((n+y-x)%n)%k==0) return true;
	else return helper(n,k,n-(((n+y-x)%n)%k),y,s);	

}


int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,k,x,y,j;
		cin>>n>>k>>x>>y;
		int temp=0;
		k=k%n;
	//	vector<int> (n,false);
		if(x==y) cout<<"YES\n";
		else if(k==0) cout<<"NO\n";
		else if(((n+y-x)%n)%k==0) cout<<"YES\n";
		else cout<<"NO\n";
	}	


	return 0;

}
