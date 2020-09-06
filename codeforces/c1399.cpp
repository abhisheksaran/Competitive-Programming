#include<bits/stdc++.h>
using namespace std;

/*
*@author saran
*@name- 
*@type-
*@date-
*/

int waysOfSum(int w[], int s,int n){
	
	int i=0;
	int j=n-1;
	
	int ans=0;
	while(i<j){
		if(w[i]+w[j]==s) {
			ans++;
			i++;
			j--;
		}
		else if(w[i]+w[j]<s) i++;
		else j--;		
		
	}
	
return ans;
}

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		int w[n];
		for(int j=0;j<n;j++) cin>>w[j];
		sort(w,w+n);
		int sum[101]={0};
		
		for(int j=0;j<101;j++) sum[j]=waysOfSum(w,j,n);
/*
		for(int j=0;j<n-1;j++){
			for(int k=j+1;k<n;k++){
				sum[w[j]+w[k]]++;	
			}
		}
*/
		int ans=0;
		for(int j=0;j<101;j++){
			ans=max(ans,sum[j]);
		}
		cout<<ans<<"\n";
	}

return 0;
}
