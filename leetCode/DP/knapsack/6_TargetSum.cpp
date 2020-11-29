/*
 * @author: saran
 * Input: array size, array, sum 
 * Output: Print the number of ways the sum can be obtained by allowing two operation for each ele-  addition or subtraction.
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> arr;
	int c_sum=0;
     	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		c_sum+=x;
	       	arr.push_back(x);	
	}
	int sum;
	cin>>sum;

	//s1+s2 = c_sum
	//s1-s2 = sum
	//s2 = (c_sum-sum)/2
	
	int s2;
	if((c_sum - sum)%2==1) {
		cout<<0<<"\n";
		return 1;
	}
	else s2 = (c_sum-sum)/2;

	vector<vector<int> > dp(n+1,vector<int> (s2+1,0));
	//base conitions
	for(int j=0;j<=s2;j++) dp[0][j]=0;
	for(int i=0;i<=n;i++) dp[i][0]=1;

	for(int i=1;i<=n;i++){
		for(int j=0;j<=s2;j++){
			if(arr[i-1]>j) dp[i][j] = dp[i-1][j];
			else dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];

		}
	}
	cout<<dp[n][s2]<<"\n";

	return 0;
}
/*
 * Hint1: 
 * two subsets- first positive marked eles and seond negative marked eles
 * Hint2:
 * What is required is the diff of those two subsets equal to given sum
 * Hint3: 
 * Reduced to prob 5_ subsetSumDifference
 * The problem is similar of dividing the array in subset partition of having subset sum diff = given sum input.
 */
