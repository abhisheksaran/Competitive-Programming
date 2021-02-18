/* @author: saran
 * Git: https://github.com/abhisheksaran
 * LinkedIn: https://www.linkedin.com/in/abhishek-saran-2900b/
 */

#include<bits/stdc++.h>
using namespace std;
int n = 1000000;
void getPrimesTillN(vector<int>& primes){
	for(int p=2; p*p <=n; p++){

		if(primes[p]==true){

			for(int i=p*p; i<=n; i+=p){
				primes[i] = false;
			}
		}
	}
	return;
}


int main(){
	ios_base::sync_with_stdio(false);
   	cin.tie(NULL);
	int t;
	cin>>t;

	//get prime till 10^6;
	vector<int> primes(n+1, true);
	getPrimesTillN(primes);
	vector<int> listOfPrimes;
	for(int i=2;i<=n;i++){
		if(primes[i]) listOfPrimes.push_back(i);
	}
	//cout<<listOfPrimes.size()<<"\n";

	for(int i=0;i<t;i++){
		int x,y;
		cin>>x>>y;
		/*
		//for subtask 1
		if(y==1){
			if(x<3) cout<<"Chef\n";
			else cout<<"Divyam\n";
		}
		//for subtask 2
		else if(y==2){
			if(x<5) cout<<"Chef\n";
			else cout<<"Divyam\n";
		}
		else cout<<"Chef\n";
		*/
		
		//general case
		//if x is less than (y+1)th prime than chef will win other wise Divyam will win.
		
		if(y > listOfPrimes.size()-1 || x < listOfPrimes[y]) cout<<"Chef\n";
		else cout<<"Divyam\n";
		
	}

	return 0;
}
