#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int m,j;
		cin>>m;
		string s;
		cin>>s;
		vector<int> count(26,-1);
		int minn=m;
		for( j=0;j<m;j++){
			if(count[(s[j]-'a')]!=-1) 
				if(j-count[(s[j]-'a')]<minn) minn=j-count[(s[j]-'a')];
			count[(s[j]-'a')]=j;
		}
		//if(minn==m+1) cout<<0<<"\n";
		cout<<m-(minn)<<"\n";
	}
return 0;
}
//two identical subsequnce but  at least one index different
//if no repetitive character, answer will be zero
//if many repetitive char is there, we can choose two out of them which are nearest, beacause this way you can maximize the k,
