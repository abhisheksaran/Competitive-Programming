#include<bits/stdc++.h>
using namespace std;
const int INF=1000000;
typedef vector<int> BigInt;
int main(){
	int a;
		vector<int> arr;
	while(cin>>a){
		if(a==-999999) {
			int n=arr.size();
			vector<int> max0(n);
				// dp when current is not taken
			vector<int> max1(n);
			vector<int> min0(n);
			vector<int> min1(n);
			max0[0]=-INF;
			max1[0]=arr[0];
			min0[0]=INF;
			min1[0]=arr[0];

			for(int i=1;i<n;i++){
				max0[i]=max(max0[i-1],max1[i-1]);
				max1[i]=max(arr[i]*min1[i-1],max(arr[i],arr[i]*max1[i-1]));

				min0[i]=min(min0[i-1],min1[i-1]);
				min1[i]=min(arr[i]*max1[i-1],min(arr[i],arr[i]*min1[i-1]));
			}
			cout<<max(max0[n-1],max1[n-1]);
			cout<<"\n";
			arr.clear();
			
		}
		else arr.push_back(a);
	}
	cout<<"\n";
	return 0;
}

			
