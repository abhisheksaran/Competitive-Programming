/*
 * @author: saran
 * Input: array size, array and sum
 * Output: Print Yes if the there exist a subset of array values which sums to given sum else print No.
 */
#include<bits/stdc++.h>
using namespace std;

/**
 * @param arr	the set of values 
 * @param n	the size of the set
 * @param S	the desired sum 
 * @param sum 	the sum of subset 
 */
bool helperRec(vector<int> arr, int n, int S){
	//base cases
	if(S==0) return true;
	if(n==0) return false;
	
	//two possibilities- either we take the current ele into the subset or we don't 
	if(arr[n-1]>S) return helperRec(arr, n-1, S);
	else return helperRec(arr, n-1, S-arr[n-1]) or helperRec(arr, n-1, S);

}

int helperRecDP(vector<int> arr, int n, int S, vector<vector<int>> &dp){
	//base cases
	if(S==0) return 1;
	if(n==0) return 0;
	
	if(dp[n][S]!=-1) return dp[n][S]; 

	//two possibilities- either we take the current ele into the subset or we don't 
	if(arr[n-1]>S) dp[n][S] = helperRecDP(arr, n-1, S, dp);
	else dp[n][S]= (helperRecDP(arr, n-1, S-arr[n-1], dp) or helperRecDP(arr, n-1, S, dp));
	return dp[n][S];
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
	int S;
	cin>>S;

	//recursive solution 
	if(helperRec(arr,n,S)) cout<<"Yes\n";
	else cout<<"No\n";
	
	//dp solution 
	//Overlapping subproblem, can have boolean matrix t[i][sum] which stores 0 if subproblem (subarr(i), sum) is true else it stores 1;
	vector<vector<int> > dp (n+1,vector<int> (S+1,-1));
	if(helperRecDP(arr, n, S, dp)) cout<<"Yes\n";
	else cout<<"No\n";
	

	//bottom up solution 
	vector<vector<bool> > dp2 (n+1,vector<bool> (S+1,false));

	//base cases
	for(int j=0;j<=S;j++) dp2[0][j] = false;
	for(int i=0;i<=n;i++) dp2[i][0] = true; 
	
	//iterative recursion
	for(int i=1;i<=n;i++){
		for(int j=0;j<=S;j++){
			if(arr[i-1]>j) dp2[i][j] = dp[i-1][j];
			else {
				dp2[i][j] = dp2[i-1][j] or dp2[i-1][j-arr[i-1]] ;
			}
		}
	}
	if(dp2[n][S]) cout << "Yes\n";
	else cout<< "No\n";	

	return 0;
}
