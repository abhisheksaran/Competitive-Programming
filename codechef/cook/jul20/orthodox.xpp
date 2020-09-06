#include<bits/stdc++.h>
using namespace std;

/*
*@author saran
*@name 
*@type
*/

int main(){
int t;
cin>>t;
int n;
for(int i=0;i<t;i++){
	cin>>n;	
	int freq[26]={0};
	int temp=0;
	char c;
	for(int j=0;j<n;j++){
		cin>>c;
		freq[c-'a']++;	
	}
	for(int j=0;j<26;j++){
		if(freq[j]%2!=0) {
			cout<<"NO\n";
			temp=1;
			break;
		}
	}
	if(temp==0)cout<<"YES\n";
}	

return 0;
}
