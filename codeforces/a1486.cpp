/* @author: saran
 * Git: https://github.com/abhisheksaran
 * LinkedIn: https://www.linkedin.com/in/abhishek-saran-2900b/
 */

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main(){
	ios_base::sync_with_stdio(false);
    	cin.tie(NULL);
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		ll sum = 0;
		int ans = 1;
		for(int j=0;j<n;j++) {
			ll arri;
			cin>>arri;
			sum += (arri);
			if(sum < ((j*(j+1))/2)) ans = 0;
		}
		if(!ans) cout<<"NO\n";
		else cout<<"YES\n";
	}

	return 0;
}
