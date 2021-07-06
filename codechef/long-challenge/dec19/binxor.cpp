#include<bits/stdc++.h>
using namespace std;
/*      this code is taken after the end of the contest just for learning purpose
	Code for calculating nCr mod P is taken from geeksforgeeks
	https://www.geeksforgeeks.org/queries-of-ncrp-in-o1-time-complexity/

typedef long long int ll;
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pb push_back


const int N = 1000001; 
// array to store inverse of 1 to N 
ll factorialNumInverse[N + 1]; 
  
// array to precompute inverse of 1! to N! 
ll naturalNumInverse[N + 1]; 
  
// array to store factorial of first N numbers 
ll fact[N + 1]; 
  
// Function to precompute inverse of numbers 
void InverseofNumber(ll p) 
{ 
    naturalNumInverse[0] = naturalNumInverse[1] = 1; 
    for (int i = 2; i <= N; i++) 
        naturalNumInverse[i] = naturalNumInverse[p % i] * (p - p / i) % p; 
} 
// Function to precompute inverse of factorials 
void InverseofFactorial(ll p) 
{ 
    factorialNumInverse[0] = factorialNumInverse[1] = 1; 
  
    // precompute inverse of natural numbers 
    for (int i = 2; i <= N; i++) 
        factorialNumInverse[i] = (naturalNumInverse[i] * factorialNumInverse[i - 1]) % p; 
} 
  
// Function to calculate factorial of 1 to N 
void factorial(ll p) 
{ 
    fact[0] = 1; 
  
    // precompute factorials 
    for (int i = 1; i <= N; i++) { 
        fact[i] = (fact[i - 1] * i) % p; 
    } 
} 
  
// Function to return nCr % p in O(1) time 
ll Binomial(ll N, ll R, ll p) 
{ 
    // n C r = n!*inverse(r!)*inverse((n-r)!) 
    ll ans = ((fact[N] * factorialNumInverse[R]) 
              % p * factorialNumInverse[N - R]) 
             % p; 
    return ans; 
} 

*/
int main(){
	int t;
	cin>>t;
	int m=1e9+7;
	vector<long long> fact(1e5+1,1);
	for(int i=2;i<=100000;i++){
		fact[i]=(i*fact[i-1])%m;
	}
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		string a,b;
		cin>>a>>b;
		int onesA=0;
		int onesB=0;
		for(int j=0;j<n;j++){
			if(a[j]=='1') onesA++;
			if(b[j]=='1') onesB++;
		}
		int onesC=onesA+onesB;
//		cout<<onesA<<" "<<onesB<<"  "<<onesC<<"\n";
		if(onesC>n)onesC=2*n-onesC;
		long long ans=0;
		if(onesA==0||onesB==0) ans=(fact[n]/(fact[max(onesA,onesB)]*fact[n-max(onesA,onesB)]))%m;
		else if(onesA==n||onesB==n) ans=(fact[n]/(fact[min(onesA,onesB)]*fact[n-min(onesA,onesB)]))%m;
		else if(onesC%2==1){
			for(int j=1;j<=onesC;j=j+2)
			ans+=(fact[n]/((fact[j]*fact[n-j])))%m;
		}	
		else{
//			cout<<"Asdfa";
			for(int j=2;j<=onesC;j=j+2)
			ans+=(fact[n]/((fact[j]*fact[n-j])))%m;
		//	cout<<onesA<<" "<<onesB<<"  "<<onesC<<"\n";
			if(onesA==onesB) ans=(ans+1)%m;
		}		
	 	
		
		cout<<ans%m<<"\n";

	}
return 0;
}


