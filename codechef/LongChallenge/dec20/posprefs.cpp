#include<bits/stdc++.h>
using namespace std;

void print(vector<int> arr,int n){
	for(int i=1;i<=n;i++) cout<<arr[i]<<" ";
	cout<<"\n";
	return;
}

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int k,n;
		cin>>n>>k;
		
		vector<int> ans(n+1,0);
		for(int j=1;j<=n;j++){
			if(j%2==1) ans[j] = j;
			else ans[j] = -j;
		}
		
		if(k==(n+1)/2) print(ans,n);
		//if we need less than what we have
		else if(k<(n+1)/2) {
			int temp = (n+1)/2 - k;
			int j = n;
			while(temp>0){
				//change positive to negative
				if(ans[j]>0) {
					ans[j] = -ans[j];
					temp --;
				}
				j--;

			}
			print(ans,n);
		}
		//if we need more
		else {
			int temp = k - (n+1)/2;
			int j = n;
			while(temp>0){
				//change neg to pos
				if(ans[j]<0) {
					ans[j] = -ans[j];
					temp --;
				}
				j--;
			}
			print(ans,n);
		}
		
	}
	return 0;
}
