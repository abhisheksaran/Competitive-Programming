#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,d,age;
		cin>>n>>d;
		int risk = 0;
		int nrisk = 0;
		for(int j=0;j<n;j++) {
			cin>>age;
			if(age >= 80 || age <= 9) risk++;
			else nrisk++;
		}
		cout<<( (risk%d == 0) ? risk/d: risk/d + 1) + ( ( (nrisk%d )==0) ? nrisk/d : nrisk/d + 1  )<<"\n"; 

	}
	return 0;
}
