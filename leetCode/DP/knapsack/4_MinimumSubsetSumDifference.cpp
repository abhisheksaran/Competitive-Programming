/*
 * @author: saran
 * Input: array size, array 
 * Output: Print the minm difference of sum of two subset partitions of given array
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> arr;
	int sum = 0 ;
     	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		sum+=x;
	       	arr.push_back(x);	
	}
	int S=sum;
	sum = ceil(sum/2.0);

	//iterative dp 
	vector<vector<bool>>  dp(n+1, vector<bool> (sum+1, false));

	//base conditions
	for(int j=0;j<=sum;j++) dp[0][j]=false;
	for(int i=0;i<=n;i++) dp[i][0]=true;

	for(int i=1;i<=n;i++){
		for(int j=0;j<=sum;j++){
			if(arr[i-1]>j) dp[i][j]=dp[i-1][j];
			else dp[i][j]=dp[i-1][j] or dp[i][j-arr[i-1]];
		}
	}
	int i;
	for( i=sum;i>=0;i--){
		if(dp[n][i]) break;
	}
	
	cout<<abs(S-i-i)<<"\n";

	return 0;
}
/*
 * Hint1:
 * s1+s2=cumalativeSum
 * we have to find min(s1-s2) = min(cumalativeSum-2*s2) (Assuming s2 smaller)  
 * Hint2:
 * Thus, we have to find what values s2 can actually take and we know s2 would be for sure less than or equal to cumalativeSum/2
 * How do we do that - as we did in subset sum problem. Find if there is a subset possible with sum = cumalativeSum/2 
 * Hint3:
 * Take last row of the table and find the maximum sum possible. 
 * Why maximum? 
 * We are trying here to find the maximum subset sum possible less than half of the cumalative sum. Such first sum will be one of the partition which will give us minimum required difference. Because as sum of one of the partition move far from half, another will move away in reverse direction increasing the difference between both of them. So what we want is first subset sum possible which is closest to the half of the cumalative sum of the given input array. 
 */

