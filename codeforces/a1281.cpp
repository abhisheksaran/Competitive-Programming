#include<bits/stdc++.h>
using namespace std;
	
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
	string s,s1,s2,s3,s4,sb1,sb2,sb3;
	cin>>s;
	s1="po";
	s2="desu";
	s3="masu";
	s4="mnida";
	int n=s.size();
	sb1=s.substr(n-2,2);
	if(sb1==s1)cout<<"FILIPINO\n";
	else if(1){
		sb2=s.substr(n-4,4);
		if(sb2==s2||sb2==s3)cout<<"JAPANESE\n";
	}
	else {
		sb3=s.substr(n-5,5);
		if(sb3==s4) cout<<"KOREAN\n";
	}
	}
return 0;
}
