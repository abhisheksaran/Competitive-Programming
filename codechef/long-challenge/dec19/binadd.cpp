#include<bits/stdc++.h>
using namespace std;
//see the pattern, AND part is seeing how many times carry is one, and carry keep coming one till next bit sum is not zero which will be both 0 or both 1, find maximum of all such carries
int main(){
	int t;
	cin>>t;
	for(int j=0;j<t;j++){
		string a,b,A,B;
		cin>>a>>b;
	int b_size=b.size();
	int a_size=a.size();
	int x=max(a_size,b_size);
	//making both strings equal
	if(x==a_size){
		for(int i=0;i<(x-b_size);i++) b.insert(0,"0");
	}
	else{
		for(int i=0;i<(x-a_size);i++) a.insert(0,"0");
	}
	int maxx=1;
	int bZero=1;
	int k;
	for(int i=x-1;i>=0;i--){
		int time=1;//imp
		if(b[i]=='1') bZero=0;//checks is b is zero or not
		if(a[i]=='1'&&b[i]=='1') {
			time++;
			for(k=i-1;k>=0;k--){ 
				if((a[k]=='0'&&b[k]=='1')||(a[k]=='1'&&b[k]=='0')){
					time++;
//					cout<<"k="<<k<<"\n";		
				}
				else break;
			}
			i=k+1;
			if(time>maxx) maxx=time;
			}
	}
		
	if(bZero==1) cout<<0<<"\n";	//if b is zero, answer is 0 else maxm is the answer
	else cout<<maxx<<"\n";
	}
return 0;
}

		
