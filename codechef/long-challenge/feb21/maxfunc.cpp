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
		int n ;
		cin>>n;
		vector<int> arr(n,0);
		for(int j=0;j<n;j++) cin>>arr[j];
		sort(arr.begin(),arr.end());
		long ans = arr[n-1]-arr[0];
		/*
		int mx =0;
		for(int j=1;j<n-1;j++){
			mx = max(mx, abs(arr[j]-arr[0])+abs(arr[j]-arr[n-1]));
		}
		ans += max
		*/
		
		cout<<2*ans<<"\n";
	}

	return 0;
}
