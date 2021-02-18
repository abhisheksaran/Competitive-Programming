#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i =0; i<t; i++){
		int k,n;
		cin>>n>>k;
		vector<int> a(n,0);
		for(int j=0; j<n; j++){
			cin>>a[j];
		}
		sort(a.begin(), a.end());
		int mike =0, tracy =0;
		int x = n-1;
		while(x>=0&& mike < k && tracy < k){
			int p = k - mike;
			int q = k - tracy;
			if(a[x]>=p && a[x]>=q){
				
				if(mike <= tracy){
					tracy += a[x--];
				}
				else{
					mike += a[x--];
				}
			}
			else if(a[x]>= p){
					mike += a[x--];
			}
			else if(a[x]>= q){
					tracy += a[x--];
			}
			else {
				if(mike >= tracy){
					tracy += a[x--];
				}
				else{
					mike += a[x--];
				}
			}
			cout<<"mike= "<<mike<<" ,tracy= "<<tracy<<"\n";
			
		}
		if(mike >= k && tracy >= k ) cout<<n-x+1<<"\n";
		else if(mike< k){
			while(x>=0 &&  mike <k){
				mike += a[x--];
			}
			if(mike >= k) cout<<n-x+1<<"\n";
		}
		else{
			while(x>=0 && tracy < k){
				tracy += a[x--];
			}
			if(tracy >= k) cout<<n-x+1<<"\n";
		}
		
		if(mike<k || tracy <k) cout<<-1<<"\n";
	}
			
	return 0;
}
