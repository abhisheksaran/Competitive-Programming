#include<bits/stdc++.h>
using namespace std;
		
int main(){
int t;
cin>>t;
for(int i=0;i<t;i++){
	string s;
	cin>>s;
	int zeros=0;
	int even=-1;
	int sum=0;
	for(int j=0;j<s.size();j++){
		sum=sum+(s[j]-'0');
		if(s[j]=='0') zeros++;
		else if((s[j]-'0')%2==0) even=1;
	}
	
	if((s=="06")||(sum%3==0&&((even==1&&zeros>=1)||(even==-1&&zeros>1)))) cout<<"red\n";
	else cout<<"cyan\n";
	}
return 0;
}
