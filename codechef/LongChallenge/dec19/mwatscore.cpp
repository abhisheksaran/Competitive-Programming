#include<bits/stdc++.h>
using namespace std;

int main(){
	int t,p,s;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		vector<int> best(8,0);
		for(int j=0;j<n;j++){
			cin>>p>>s;
			p--;
			if(p<8&&best[p]<s)best[p]=s;
		}
		int sum=0;
		for(int j=0;j<8;j++) sum+=best[j];
		cout<<sum<<"\n";
	}
	return 0;
}
				
