#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		vector<int> arr(n,0);
		int odd = 0, even =0;
		for(int j=0;j<n;j++){
		       	cin>>arr[j];
			if(int(arr[j]&1) == 0) even++;
			else odd++;

		}
//		cout<<even<<" "<<odd<<"\n";
		if(odd == 0) cout<<2*(even-1);
		else if(even ==0) cout<<2*(odd-1);
		else cout<<min(2*(even-1)+odd, 2*(odd-1)+even);

		if(i!= (t-1) ) cout<<"\n";
	}

	return 0;
}

