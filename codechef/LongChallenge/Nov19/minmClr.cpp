#include<bits/stdc++.h>
using namespace std;
/*
long solve(vector< pair <long,long > > arr,vector<long> count,int minm,int max,int flag ){
	if(flag==0) count[arr[minm-1].second]--;
	if(flag==1) count[arr[max+1].second]--;
		while(1){
			//cout<<"max="<<max<<" minm="<<min<<"\n";
			if(count[arr[max].second]>1 && count[arr[minm].second]>1){//at least there should be one element in the min-max range 
				if(arr[max-1].first-arr[minm].first < arr[max].first - arr[minm+1].first) {//two possibilites, either decrease max or increase min
					count[arr[max].second]--;
					max--;	
				}
				else if(arr[max-1].first-arr[minm].first > arr[max].first - arr[minm+1].first) {
					count[arr[minm].second]--;
					minm++;
				}
				else {//suppose both possibilties give equal current reward
					int a=solve(arr,count,minm+1,max,0);
					int b=solve(arr,count,minm,max-1,1);	
					return min(a,b);//look for minm future reward
				}

			}
			else if(count[arr[max].second]>1){
				count[arr[max].second]--;
				max--;
			}
			else if(count[arr[minm].second]>1){
				count[arr[minm].second]--;
				minm++;
			}
			else{
			//	cout<<"@max="<<max<<" minm="<<min<<"\n";
				 return arr[max].first-arr[minm].first;// return max_ele - min_ele as answer to the given range
			}
		}

}
*/
//question wants us to minimize max-min, which means we have to user a similar approach of two pointer
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,m;
		cin>>n>>m;
		vector< pair<long,long> > arr;//store the box and it's corresponding color, permutation of color doesn't matter
		vector <long> count (m,0);//store the number of boxes of each color
		for(int j=0;j<n;j++){
			long x;
			cin>>x;
			arr.push_back({x,j%m});
			count[j%m]++;
		}
		sort(arr.begin(),arr.end());
		//long ans =solve(arr,count,0,n-1,-1);//intially min at 0 at max at n-1 
		// reamark= this approach won't work take this example 1,2,5,8,9,11 where {1,8}, {2,9}, {5,11} are same coloring boxes , this aporaoch won't give the optimal answer which is {8,9,11};
		//still we will use two pointer but now in the right manner 

		int l=0;
		int r=0; 
		long ans =1e9; 
		vector <long> crrcnt (m,0);//store the number of boxes of each color
		int clr=0; 
		while(1) {
			if(clr<m) {
				if(r>=n) break;
				if(crrcnt[arr[r].second]==0) clr++;
				crrcnt[arr[r].second]++;
				r++;
			}
			else if (clr==m){
				if(crrcnt[arr[l].second]==1) clr --;		
				crrcnt[arr[l].second]--;
				l++;
			}

			if(clr==m) {
				ans=min(ans,(arr[r-1].first-arr[l].first));
			//	cout<<l<<" " <<r<<" " <<ans<<"\n";
			}		
		}
		cout<<ans<<"\n";
	}
	return 0;
}

			
			
			
		
		
			
			
