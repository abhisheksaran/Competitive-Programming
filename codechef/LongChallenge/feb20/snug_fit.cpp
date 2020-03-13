#include<bits/stdc++.h>

using namespace std;

int main(){
int t;
cin>>t;
for(int i=0;i<t;i++){
	int n;
	cin>>n;
	vector<int > a(n,0);
	vector<int > b(n,0);
	for(int j=0;j<n;j++) cin>>a[j];
	for(int j=0;j<n;j++) cin>>b[j];
	sort(a.begin(),	a.end());
	sort(b.begin(),	b.end());
	long long sum=0;	
	for(int j=0;j<n;j++) sum+=min(a[j],b[j]);
	cout<<sum<<"\n";
}
return 0;
}
