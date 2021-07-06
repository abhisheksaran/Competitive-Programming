#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int c=2<<20;
		cout<<1<<" "<<c;
		cin>>c;
		
		int ans=0;
		int carry =0;
		for(int j=0;j<20;j++){
			if(c&1==0){
				if(n&1==1){
					ans=ans+2<<j;		
				}			
			}	
			else if(n&1==0) ans=ans+2<<j;
		}
		
	}

return 0;
}
