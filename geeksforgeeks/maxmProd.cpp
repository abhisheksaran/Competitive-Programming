#include<bits/stdc++.h>
using namespace std;

/*
*@author saran
*@name- Given a rope of length n meters, cut the rope in different parts of integer lengths in a way that maximizes product of lengths of all parts.
*@type- DP/Tricky
*@date-3rd Aug 2020
*/

int main(){

	int n;
	cin>>n;
		
	int maxProd[n+1];
	maxProd[1]=1;
	for(int i=2;i<=n;i++){
		maxProd[i]=i-1;
		for(int j=2;j<=(i/2);j++){
			maxProd[i]=max(maxProd[i],max(j*(i-j),maxProd[j]*maxProd[i-j]));	
		}
	cout<<i<<" "<<maxProd[i]<<"\n";
	}

	cout<<maxProd[n]<<"\n";
return 0;
}
//observation: keep cutting the rope in length of 3 till length is greter than 4.
