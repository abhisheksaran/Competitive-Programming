#include<bits/stdc++.h>
using namespace std;

/*
*@author saran
*@name Partition a set in two sets such that the absolute diff between sum of elements of those two sets is minimum  
*@type DP
*@date 21th July
*/

int main(){
	vector<int> inp;
	int n;
	cin>>n;
	int sum[n];	

	for(int i=0;i<n;i++){
		int c;
		cin>>c;
		if(i>0) sum[i]=c+sum[i-1];
		else sum[0]=c;
		inp.push_back(c);
	}
	int totalSum=sum[n-1];
	//dp[i][s] is true iff sum s can be obtained using first i element 
	bool  dp[n+1][totalSum+1]={false};

	//initialization
	for(int i=0;i<=totalSum;i++) dp[0][i]=false;
	for(int i=0;i<=n;i++) {
		dp[i][0]=true;
	}
	
	for(int i=1;i<=n+1;i++){
		
		for(int j=1;j<=totalSum;j++){	
			if(j-inp[i-1]>=0) dp[i][j]=dp[i][j-inp[i-1]];//include the current number 
	
			dp[i][j]=dp[i-1][j]||dp[i][j];// don't include current number
			
		}
	}
	
	int ans=-1;
	for(int j=totalSum/2;j>=0;j--){
		cout<<"sum="<<j<<" is possible using all "<<n<<" elements="<<dp[n][j]<<"\n";
		if(dp[n][j]){
			ans=abs(j-(totalSum-j));	
			break;	
		}
		
	
	}
	
	cout<<"_________________the min diff of partition is="<<ans<<"______________________\n";
	

return 0;
}
