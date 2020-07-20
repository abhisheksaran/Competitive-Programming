#include<bits/stdc++.h>
using namespace std;

/*
*@author saran
*@name Longest Increasing Subsequences 
*@type normal solution
*/

int main(){

int n;
cin>>n;
int a[n];
for(int i=0;i<n;i++) cin>>a[i];

//vectot will finally store the resulting subarray.
vector<int> ans;
ans.push_back(a[0]);

//vector stores the index of values inserted in vector ans
vector<int> index;
index.push_back(0);

//to keep track of potential new values or active sequence.
int first=1;
int cnt=1;

for(int i=1;i<n;i++){
	//condition to add new ele
	if(a[i]>a[i-1]){
		//ans.push_back(a[i])
		index.push_back(i);
		first=i+1;
		cnt=1;
	}	

	//condition to update 
	else if(a[first-cnt]>a[first]&&(first-cnt-1==-1||a[first-cnt-1]<a[first]))
	{	
		for(int j=0;j<cnt;j++){
			index[first-cnt+j]=a[first+j];
		}
		//reset the update tracking numbers
		first=i+1;
		cnt=1;

	}


	//condition to add to potential new values 
	else if(a[i]>a[first+cnt-1]){
		cnt++;
							
	}

	

}
cout<<index.size()<<"\n";






return 0;
}
