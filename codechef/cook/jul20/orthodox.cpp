#include<bits/stdc++.h>
using namespace std;

/*
*@author saran
*@name 
*@type
*/

int main(){
int t;
cin>>t;
int n;
for(int i=0;i<t;i++){
	cin>>n;	
	int temp=0;
	int  a,last;
	for(int j=0;j<n;j++){
		cin>>a;
		if((ceil(log2(a+1))==floor(log2(a+1)))&&(j!=0)) temp=1;
		
		if((ceil(log2(a)) ==floor(log2(a)))&&j!=(n-1)&&a!=1) temp=1;
		
		if(a%2==1&&j>0&&last==1) temp=1;
		last=a;
	}
	if(temp==0)cout<<"YES\n";
	else cout<<"NO\n";
}	

return 0;
}
