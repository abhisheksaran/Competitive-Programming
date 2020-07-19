#include<bits/stdc++.h>
using namespace std;
int primeFactors(int n){
	int x=n;
	int cnt=0;
	while(n%2==0){
		n=n/2;
		cnt++;
	}
	for(int i=3;i*i<=n;i=i+2){
		while(n%i==0){
			n=n/i;
			cnt++;
		}
	}
//	cout<<n<<" "<<cnt<<"\n";
	if(n>2) cnt++;
	return cnt;
}
// number of total facctors = mult of (ai+1) 
// number of prime facctors = i
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++) {
		int x,k;
		cin>>x>>k;
		int d;
		if (x==1) cout<<0<<"\n";
		else if(k==1) cout<<"1\n"; 
		else { 
			d=primeFactors(x);
			if(k<=d) cout<<1<<"\n";
			else cout<<0<<"\n";
		}	
//		cout<<"number of factors of "<<x<<"="<<d<<"\n";
		
	}
	return 0;

}
// you just have to think about getting factors of x except '1',
// k can be anything less than equal to number of factors
