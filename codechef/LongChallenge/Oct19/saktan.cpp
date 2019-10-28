#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,m,q;
		cin>>n>>m>>q;
		vector<int> row (n,0);
		int row_even=n;
		vector<int> clm (m,0);
		int clm_even=m;
		for(int j=0;j<q;j++){
			int a,b;
			cin>>a>>b;
			a--;
			b--;
			row[a]++;
			clm[b]++;
			if(row[a]%2==0) row_even++;
			else row_even--;
			if(clm[b]%2==0) clm_even++;
			else clm_even--;
		}
		int ans;
		ans=row_even*(m-clm_even)+clm_even*(n-row_even);
		cout<<ans<<"\n";
	}
	return 0;
}

			
		
