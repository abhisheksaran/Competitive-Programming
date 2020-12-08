#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,x;
		cin>>n>>x;
		vector<int> arr(n,0);
		for(int j=0;j<n;j++) cin>>arr[j];
		
		//count the bits at each pos
		vector<int> bitcount(31,0);
		for(int j=0;j<n;j++){
			for(int k=0;k<31;k++){
				int temp = 1<<k;
				//cout<< temp <<" "<<arr[j]<<" "<<int(temp & arr[j])<<"\n";
				if(int(temp & arr[j]) > 0) bitcount[k]++;
			}
	
		}	
		
		//debug
		/*
		for(int j=0;j<30;j++) cout<<bitcount[j]<<" ";
		cout<<"\n";
		*/

		//simuate answer
		vector<int> carry(31,0);
		for(int j=0;j<n-1;j++){
			//take care of carry of last iteration
			for(int k = 30;k>=0 ;k--){
				if(carry[k] > 0 && int(1<<k & arr[j]) > 0) {
					arr[j] = arr[j] xor (1<<k);
					carry[k]--;
					
				}
			}
			
			if(x>0){
				//calculate carry for current iteration
				for(int k=30; k>=0 && x>0 ;k--){
					//if it  can get a pair (there exists a common setbit pos )
					if(int(arr[j] & (1<<k)) > 0 && bitcount[k] >= 2){
						arr[j] = arr[j] xor (1<<k);
						bitcount[k]-=2;
						carry[k]++;
						x--;
					}
					//else take last ele as second ele of pair
					else if(int(arr[j] & (1<<k)) > 0){
						arr[j] = arr[j] xor (1<<k);
						bitcount[k]--;
						carry[k]++;
						x--;
					}
				}
			}
		}
		//apply all the carry on last ele
		for(int k=30; k>=0; k--){
			if(carry[k] == 1){
			       	arr[n-1] = arr[n-1] xor (1<<k);
			}
		}


		//if still x>0, that means all the n-1 elements are zero and we will do all remaining operations on last two eles
		if(x > 0 ){
			//cout<<"asdf ";
			//if x is even we all xor operation will cancel each other else xi is odd, we will apply the opration once on last ele taking p =0
			if(x%2 == 1){
				arr[n-1] = arr[n-1] xor (1);
				arr[n-2] = arr[n-2] xor (1);
			}
		}

		//print the ans
		for(int j=0;j<n;j++) cout<<arr[j]<<" ";
		cout<<"\n";

	}	
	return 0;
}
