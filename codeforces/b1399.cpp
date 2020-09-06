#include<bits/stdc++.h>
using namespace std;

/*
*@author saran
*@name- 
*@type-
*@date-
*/

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin >>n;
		int a[n];
		int b[n];
		int minb=1e9+1;
		int mina=1e9+1;
		for(int j=0;j<n;j++){
			cin>>a[j];	
			mina=min(mina,a[j]);
		}
		for(int j=0;j<n;j++){
			cin>>b[j];	
			minb=min(minb,b[j]);
		}


//		cout<<mina<<" "<<minb<<"\n";	
		long long sum=0;
		for(int j=0;j<n;j++){
			sum+=max(a[j]-mina,b[j]-minb);
			
		}
		cout<<sum<<"\n";
	}
	

return 0;
}
