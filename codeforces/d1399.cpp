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
		string a;
		cin>>a;
	
		int zero=0;
		int one=0;
		
		vector<int> ans;
		int m=0;
		for(int i=0;i<n;i++){
		
			if(a[i]=='0') {
				zero++;
				one--;
				if(one<0) one=0;
				ans.push_back(zero);
				m=max(m,zero);
			}
			else{
				one++;
				zero--;
				if(zero<0) zero=0;
				ans.push_back(one);
				m=max(m,one);
			}
			//ans.push_back(max(zero,one));
			//m=max(m,max(zero,one));
			
		
		}
		cout<<m<<"\n";
		for(int j=0;j<ans.size();j++) cout<<ans[j]<<" ";
		cout<<"\n";



	}

return 0;
}
