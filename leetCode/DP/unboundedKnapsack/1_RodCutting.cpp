/* @author: saran
 * Input: length of the rod, the size of array of possible cut length, the cut length array and price array of each cut length
 * Output: Find the price of maximum value cut.  
 */
#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int l;
	cin>>l;
	vector<int> arr;
	vector<int> price;
     	for(int i=0;i<l;i++){
		int x;
		cin>>x;
	       	arr.push_back(x);	
	}
	for(int i=0;i<l;i++){
		int x;
		cin>>x;
	       	price.push_back(x);	
	}
	// the dp because we are given an array we are told to find sth optimal
	//we can use same cut size again which leads to the identification it as a queation of unbounded knapsack
	//what would be recursion- MaxmPrice(n)=max(MaxmPrice(n-cutSize) where cutSize ranges over 1 to n.
	//What would be memozation- to save maxmPrice of a length once it is calculated
	
	vector<vector<int>> dp(n+1, vector<int>(l+1,0));
	//base conditions
	//if rod is of size 0, it can't be cut. Thus, maximum possible price of cuts is 0.
	for(int j=0;j<=n;j++) dp[0][j] = 0;
	//if there is no possible cut, Maximum price of cuts will be zero in this case as well.
       	for(int i=0;i<=l;i++) dp[i][0] = 0;	

	for(int i=1;i<=n;i++){
		for (int j=1;j<=l;j++){
			if(i<arr[j-1]) dp[i][j] = dp[i][j-1];
			else dp[i][j] = max( price[j-1]+ dp[i-arr[j-1]][j], dp[i][j-1]);
		}
	}

	cout<<dp[n][l]<<"\n";
	return 0;
	
}
//hint : unbounded knapsack 
