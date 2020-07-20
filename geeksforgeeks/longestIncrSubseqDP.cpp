#include<bits/stdc++.h>
using namespace std;

/*
*@author saran
*@name Longest Increasing Subsequences 
*@type DP
*/

int CeilIndex(vector<int> &tail, int key){
	int l=0;
	int r=tail.size()-1;

	while(r-l>1){
		int m=l+(r-l)/2;
		if(key>tail[m]) l=m;
		else r=m;
	}
	return r;
}

void visualize(int x,vector<int> tail, vector<int> cnt){
	cout<<"configuration atter "<<x<<"th iteration >>\n";
	for(int i=0;i<tail.size();i++){
		cout<<"elements in current seq="<<cnt[i]<<" last element of current seq="<<tail[i]<<"\n";
	}
	

}

int main(){

	int n;
	cin>>n;
	int a[n];

	cout<<"input>>";
	for(int i=0;i<n;i++) {
		cin>>a[i]; 
		cout<<a[i]<<" ," ;
	}
	cout<<"\n";
	//ith entry is number of elements in ith list 
	vector<int> cnt;
	//ith entry contains the last element in ith list 
	vector<int> tail;

	cout<<"_________________iteration 0___________________\n";
	
	tail.push_back(a[0]);
	cnt.push_back(1);
	
	visualize(0,tail,cnt);
	for(int i=1;i<n;i++){
		
		cout<<"_________________iteration "<<i<<"___________________\n";
		cout<<"val="<<a[i]<<" ";
		int cntActSeq= tail.size();
		if(tail[0]>a[i])  {
			tail[0]=a[i];
			cout<<"case 1: start new active sequence\n";
		}

		else if(a[i]>tail[cntActSeq-1]) { 
			tail.push_back(a[i]) ;
			cnt.push_back(cnt[cntActSeq-1]+1);
			cout<<"case 2: clone the largest active seq and extend\n";	
		}
		
		else {
			tail[CeilIndex(tail, a[i])]=a[i];
			cout<<"case 3: clone extend discard\n";
		}	
		visualize(i,tail,cnt);

	}
					
	cout<<tail.size();
return 0;
}
