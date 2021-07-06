#include<bits/stdc++.h>
using namespace std;
	
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int cnt_zero=0;
		int cnt_two=0;
		for(int j=0;j<n;j++){
			long a;
			cin>>a;
			if(a==0) cnt_zero++;
			if(a==2) cnt_two++;
		}
		cout<< ((cnt_zero*(cnt_zero-1))/2)+((cnt_two*(cnt_two-1))/2)<<"\n";

	}
return 0;
}
	
