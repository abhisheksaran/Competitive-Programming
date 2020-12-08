#include<bits/stdc++.h>
using namespace std;

int main(){
	int d1,v1,d2,v2,p;
	cin>>d1>>v1>>d2>>v2>>p;
	int d = 0;
	int v = 0;
	while(v<p){
		d++;
		if(d>=d1) v+=v1;
		if(d>=d2) v+=v2;
	}
	cout<<d<<"\n";
	return 0;
}
