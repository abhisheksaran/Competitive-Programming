#include<bits/stdc++.h>
using namespace std;

int main(){

	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,p;
		cin>>n>>p;
		vector<int > coins(n);
		for(int j=0;j<n;j++) cin>>coins[j];

		int j;
		int temp=0;
		for(j=0;j<n;j++) {
			if(p%coins[j]!=0) {//case 1: P has to be multiple of all the coins
				temp=1;
				break;
			}
			if(j>0 && coins[j]%coins[j-1]!=0) {//case2: Each next coin has to be multiple of current coin
				temp=2;
				break;
			}
		}
		if(j==n) cout<<"NO\n";
		else if (temp==1){
		       	cout<<"YES ";
			for(int k=0;k<n;k++){
				if(k==j){
					cout<<(p/coins[j])+1;//easy case just print factor+1
				}
				else{
					cout<<0;
				}
				cout<<" ";
			}
			cout<<"\n";
		}
		else if (temp==2) {
			cout<<"YES ";
		
			for(int k=0;k<n;k++){//print< factor(p,coins[j]) -1> at j and   < factor ( p-factor*coins[j],coins[j-1]) +1 >  where factor(i,j)=i/j and obvio i%j=0
// a doubt which can arose here is why -1 is correspond to coins[j] and +1 to coins[j-1]
//because if we do that way condition "if any coin is removed from this multiset, the total worth of the remaining coins is strictly smaller than P." will not be satified.
				if(k==j-1){
					cout<<(p-(p/coins[j]-1)*coins[j])/coins[j-1]+1;
				}
				else if(k==j)
					cout<<(p/coins[j])-1;
				else{
					cout<<0;
				}
				cout<<" ";
			}
			cout<<"\n";
	
		}


	}
	return 0;
}
	

