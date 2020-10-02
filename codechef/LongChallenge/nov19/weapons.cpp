#include<bits/stdc++.h>
using namespace std;
//simply take xor of all stings 
//the number if ones in resultant string will be the answer
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		vector<int> xorOF(10,0);
		for(int j=0;j<n;j++){
			string s;
			cin>>s;
			for(int k=0;k<10;k++){
				if(s[k]=='1') xorOF[k]++;//count total number of 1 at each position 
			}
		}
		int ans=0;	
		for(int j=0;j<10;j++){
			if(xorOF[j]%2==1) ans++;//the position where number of one is odd,winner could have weapon no ='position' 
		}
		cout<<ans<<"\n";
	}
return 0;
}
