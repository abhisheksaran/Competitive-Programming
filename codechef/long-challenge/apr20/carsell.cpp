#include<bits/stdc++.h>
using namespace std;
#define m 1000000007;
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int j,n;
		int sum=0;
		cin>>n;
		vector<int > in(n,0);
		for(j=0;j<n;j++) cin>>in[j];
		sort(in.begin(),in.end(), greater<int>() );		
		//calculating the maxm profit 
		
		for(j=0;j<n;j++) {
			if(in[j]-j<=0) break;
			sum+= (in[j]-j);
			sum%= m;
		}
		cout<<sum<<"\n";

	}


return 0;
}
