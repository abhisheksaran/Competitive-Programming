#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		string s;
		cin>>s;
		int n = s.length();

		//calculate number of ones 
		vector<int> ones(n+1,0);
		for(int j=1;j<=n;j++) {
			ones[j]= (s[j-1]=='1')?  ones[j-1]+1 : ones[j-1];
//			cout<<ones[j]<<"\n";
		}

		unordered_map <string, int> um;
		int ans = 0 ;
		for(int j=0;j<n;j++){
			for(int k=1;k<=n-j;k++){
				string substring = s.substr(j,k);
//				cout<<j<<" "<<k<<" "<<substring<<" "<<ones[j+k]<<" "<<ones[j]<<"\n";
				if(um.find(substring) == um.end()){
						
					if((ones[j+k]-ones[j]) % 2 ==0 ){
						reverse(substring.begin(),substring.end());
						if(um.find(substring) == um.end()) {
							um[substring] = 1;
							ans++;
//							cout<<substring<<" type1\n";
						}
					}
					else{
						um[substring] = 1;
						ans++;
//						cout<<substring<<" type2\n";
					}
				}
			}
		}
		cout<<ans<<"\n";
	}
	return 0;
}
