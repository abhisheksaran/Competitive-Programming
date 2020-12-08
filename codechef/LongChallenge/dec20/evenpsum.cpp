#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	long long a,b;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>a>>b;
		cout<<(a/2)*(b/2)+(a-(a/2))*(b-(b/2)) <<"\n";
	}
	return 0;
}
