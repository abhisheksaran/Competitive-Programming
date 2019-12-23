#include<bits/stdc++.h>
using namespace std;
		
int main(){
	int a,b,c,d,e,f;
	cin>>a>>b>>c>>d>>e>>f;
	int x=min(a,d);
	int y=min(b,min(c,d));
	int z=0;//cost
	if(e>f){
		z=x*e;
		d=d-x;
		if(d>0) z+=min(b,min(c,d))*f;
	}
	else{
		z=y*f;
		d=d-y;
		if(d>0) z+=min(a,d)*e;
	}	
	cout<<z;
return 0;
}
