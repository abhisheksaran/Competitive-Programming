#include<bits/stdc++.h>
using namespace std;

/*
*@author saran
*@name- Given a rod of length n inches and an array of prices that contains prices of all pieces of size smaller than n. Determine the maximum value obtainable by cutting up the rod and selling the pieces 
*@type-DP
*@date-25th July
*/

int main(){

	int n;
	cin>>n;
	int arr[n+1]={0};
	for(int i=1;i<n+1;i++) cin>>arr[i];
	
	for(int i=2;i<=n;i++){
		for(int j=1;j<=(i/2);j++){
			arr[i]=max(arr[i],arr[j]+arr[i-j]);
		}
	cout<<arr[i]<<"\n";
	}
	cout<<"ans="<<arr[n]<<"\n";

return 0;
}
