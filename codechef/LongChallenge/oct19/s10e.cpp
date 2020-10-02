#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		vector<int> a (n,0);
		for(int j=0;j<n;j++){
			cin>>a[j];}
		int minn=1000;
		int indexMin=0;
		int secMin=0;
		int indexSecMin=10000;
		int goodDays=0;
		for(int j=0;j<n;j++){
			if(indexMin<j-5){
				minn=secMin;
				indexMin=indexSecMin;
				if(n>=indexSecMin+2){	
					secMin=a[indexSecMin+1];
					indexSecMin=indexSecMin+1;
				}
			}
			if(a[j]<minn) {
				goodDays++;

				minn=a[j];
				indexMin=j;
				if(n>=j+2){	
					secMin=a[j+1];
					indexSecMin=j+1;
				}
			}
			if(j>indexMin&&a[j]>=minn&&a[j]<secMin)
			{
				secMin=a[j];
				indexSecMin=j;
			}
		cout<<"min="<<minn<<"\n";
		cout<<"second min=" <<secMin<<"\n";
		}
		cout<<goodDays<<"\n";
	}
	return 0;
}
			
			
