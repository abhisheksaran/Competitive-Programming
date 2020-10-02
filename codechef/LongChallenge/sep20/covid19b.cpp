#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int v[n];
		for(int j=0;j<n;j++) cin>>v[j];
		vector<int> ans;
		for(int j=0;j<n;j++){
			bool infected[n];
			memset(infected,false,sizeof(infected));
			infected[j]=true;
			// those whom he will cross
			for(int k=j+1;k<n;k++){
				if(v[k]<v[j]){
					infected[k]=true;
					//these will infact whoever crosses them
					for(int l=0;l<=j;l++){
						if(!infected[l]&& v[l]>v[k] ) infected[l]=true;
					}
				}

			}
			//those who will cross him
			for(int k=0;k<j;k++){
				if(v[k]>v[j] ) {
					infected[k]=true;
					// how many of those who crossed him can crossed the player ahead of him to whom he can't directly infect
					for(int l=j+1;l<n;l++){
						if(!infected[l] && v[l]<v[k]) infected[l]=true;
					}
				}
			}
			
			int temp=0;
			for(int k=0;k<n;k++) {
				if(infected[k]) temp++;
			}

			ans.push_back(temp);
		}
		sort(ans.begin(),ans.end());
		cout<<ans[0]<<" "<<ans[ans.size()-1]<<"\n";
	}
	return 0;
}
