/*
 * @author: saran
 * Input: array size, array, diff 
 * Output: count the number of subset partitions, difference of sum of which two is given diff
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int sum = 0 ;
	vector<int> arr;
     	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		sum+=x;
	       	arr.push_back(x);	
	}
	int diff;
	cin>>diff;

	//s1-s2=diff
	//s1+s2=sum
	//s2 = sum - diff /2 where s2= is the smaller sum subset
	//the problem now reduces to finding the number of subsets with sum equal to s2
	
	int s2;
	if((sum-diff)%2==1 ){
		cout<<0<<"\n";
	}
	else s2 = (sum-diff)/2;

	vector<vector<int>> dp(n+1, vector<int> (s2+1, 0));
	
	//base conditions
	for(int j=0;j<=s2;j++) dp[0][j]=0;
	for(int i=0;i<=n;i++) dp[i][0]=1;

	//iterative dp	
	for(int i=1;i<=n;i++){
		for(int j=0;j<=s2;j++){
			if(arr[i-1]>j) dp[i][j] = dp[i-1][j] ;
			else dp[i][j] = dp[i-1][j] + dp[i-1][j-arr[i-1]];
		}
	}

	cout<<dp[n][s2]<<"\n";
	return 0;
}
