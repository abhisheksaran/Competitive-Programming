/* @author: saran
 * Git: https://github.com/abhisheksaran
 * LinkedIn: https://www.linkedin.com/in/abhishek-saran-2900b/
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,q,m;
		cin>>n>>q>>m;
		vector<int> a(n,0);
		for(int j=0;j<n;j++) cin>> a[j];
		map<pair<int,int>,int> mp; 
		//priority_queue< pair<int, pair<int,int>>, vector< pair<int, pair<int,int>>> , greater<pair<int, pair<int,int>>> > pqx;
		//priority_queue< pair<int, pair<int,int>>, vector< pair<int, pair<int,int>>> , greater<pair<int, pair<int,int>>> > pqy;
		//set< pair<pair<int,int>, pair<int,int>> pqx;
		//set< pair<pair<int,int>, pair<int,int>> pqy;
		for(int j=0;j<q;j++){
			int l,r;
			cin>>l>>r;
			if(a[l-1]<=m) mp[{a[l-1],a[r-1]}] ++;
			//mp[a[l-1]]++;
			//mp[a[r-1]+1]--;
			/* for subtask one and two
			for(int k =1; a[l-1]*k + a[r-1]*(k-1) <= m; k++){
				mp[a[l-1]*k + a[r-1]*(k-1) ]++;
			       	mp[a[l-1]*k + a[r-1]*k ]--;	
			}
			*/
			//for subtask 3
			//pqx.insert({{a[l-1],1}, {a[l-1], a[r-1]}});
			//pqy.insert({{a[l-1]+a[r-1],1}, {a[l-1], a[r-1]}});

		}
	
		vector<int> lazy(m+1,0);	
		for(auto entry:mp){
			pair<int,int> curr = entry.first;
			int l = curr.first;
		       int r = curr.second;	
			for(int k=1; l*k+r*(k-1) <= m; k++){
				lazy[l*k + r*(k-1)] += entry.second;	
				if(l*k + r*k <=m) lazy[l*k + r*k ] -= entry.second;
			}
		}
		
		int ans =0;
		int cnt =0;
		for(int i=0;i<=m;i++){
			cnt += lazy[i];
			ans = max(ans,cnt);
		}
		/*
		auto itr2 = pqy.begin();
		auto itr1 = pqx.begin();
		int j = min(*itr1.first.first, *itr2.first.first);
		for(j;j<=m;){
			itr2 = pqy.begin();
			itr1 = pqx.begin();
			if(*itr1.first.first == j){
				cnt += *itr1.first.second;
				pair<pair<int,int> ,pair<int,int>> p = *itr1;
				pqx.erase(itr1);
				p = {{p.first.first + p.second.first + p.second.second, p.first.second} ,{p.second.first,p.second.second}};
				if(pqx.fin
			}
			while(pqy.top().first==j){
				cnt--;
				pair<int,pair<int,int>> p = pqy.top();
				pqy.pop();
				pqy.push({p.first + p.second.first + p.second.second ,{p.second.first,p.second.second}});
			}
			
			j = min(pqy.top().first, pqx.top().first);
			ans = max(ans, cnt);

		}
		*/
		cout<<ans<<"\n";
	}

	return 0;
}
