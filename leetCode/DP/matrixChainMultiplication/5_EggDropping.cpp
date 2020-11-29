/*
 * @author: saran
 * Input: array size, array 
 * Output: Min num of attempts to find the critical floor. The critical floor is the first floor from where if dropped, egg would break.
 */
#include<bits/stdc++.h>
using namespace std;

int helper(vector<int> arr, int i, int j){
	if(i==j||i>j) return 0;

	int mn = INT_MAX;
	for(int k=i+1;k<j;k++){
		mn = min(mn,helper(arr,i,k)+helper(arr,k+1,j)+(arr[i-1]*arr[j-1]*arr[k-1]));
	}
	return mn;
	
}
int main(){
	int n;
	cin>>n;
	vector<int> arr;
     	for(int i=0;i<n;i++){
		int x;
		cin>>x;
	       	arr.push_back(x);	
	}

	//recursive solution 
	cout<<helper(arr,1,n)<<"\n";

	return 0;
}
