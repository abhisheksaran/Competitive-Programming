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
		cin>>n;
		int arr[n];
		for(int j=0;j<n;j++) cin>>arr[j];
		sort(arr,arr+n);
		int temp=1;
		for(int j=1;j<n;j++) {
			if(arr[j]-arr[j-1]>1) {
				cout<<"NO\n";
				temp=0;
				break;
			}
		}
		if(temp==1) cout<<"YES\n";	
	}	

return 0;
}
