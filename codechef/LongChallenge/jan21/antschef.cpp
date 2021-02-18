#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		vector<vector<int>> arr(n,vector<int>());
		vector<int> pos(n,0);
		vector<int> neg(n,0);
		unordered_map<int,int> um;
		for(int j=0; j<n; j++){
			int m;
			cin>>m;
			for(int k =0; k<m; k++){
				int x;
				cin>>x;
				if(x>0) pos[j]++;
				else neg[j]++;
				um[abs(x)]++;
				arr[j].push_back(x);
			}
			
		}
		int ans =0;
		for(int j=0;j<n;j++){
			for(int k=0;k<arr[j].size();k++){
				if(um[abs(arr[j][k])]>1) {
					if(arr[j][k]>0) ans+= arr[j].size()-1-k;
					else ans += k;
				}
				else{
					if(arr[j][k]<0) ans+= arr[j].size()-1-k;
					else ans += k;
				
				}

			}
		}
		//cout<<ans<<endl;
		for(auto i: um){
			if(i.second>1) ans++;
		}
		cout<<ans<<"\n";
	}
	return 0;
}
