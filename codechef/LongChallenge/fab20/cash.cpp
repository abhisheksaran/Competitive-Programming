#include<bits/stdc++.h>
using namespace std;

int main(){
int t;
cin>>t;
for(int i=0;i<t;i++){
	int n;
	long long k;
	cin>>n>>k;
	vector<int> a(n,0);
	long long sum=0;
	for(int j=0;j<n;j++) {
		cin>> a[j];		
		sum+=a[j];
	}
//	cout<<sum<<"\n";
	long long ans=sum%k;
	cout<<ans<<"\n";
	
}
return 0;
} 
