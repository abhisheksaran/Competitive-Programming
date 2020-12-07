#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;	
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int arr[7]={2,3,1,5,4,6,7};
		if(n==1) cout<<1<<"\n";
		else if(!(n& (n-1)) ) cout<<-1<<"\n";
		else{
			
			for(int j=1;j<=n;j++){
				if(j<=7) cout<<arr[j-1]<<" ";
				else if(!(j&(j-1))){
				//	cout<<j<<"asdf\n";
					cout<<j+1<<" "<<j<<" ";
					j++;
				}
				else cout<<j<<" ";
			}	
			cout<<"\n";	
		}
	}

	return 0;
}
