#include<bits/stdc++.h>
using namespace std;
int arr[60];
void initArr(){
	arr[0]=0;
	arr[1]=1;
	for(int i=2;i<70;i++){
		arr[i]=(arr[i-1]+arr[i-2])%10;
	}
}
int main(){
	
	int t;
	cin>>t;
	initArr();
	long long n;
	for(int i=0;i<t;i++){
		cin>>n;
		long long z=1;
		int x=0;
		while(z<n){
			z=z*2;
			x++;
		}
		if(z!=n) z=z/2;
		int m=int(z%60);
		cout<<arr[m-1]<<"\n";
	}
	return 0;
}

		
	
