#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int x=0;x<t;x++){
		int n;
		cin>>n;
		vector<pair<long,int> > terpts;//terminal points;
		vector<int> nuCmnRng;//number of common range at particular point
		
		for(int i=0;i<n;i++){
			int l,r;
			cin>>l>>r;
			terpts.push_back({l,1});
			terpts.push_back({r,-1});
		}
		sort(terpts.begin(),terpts.end());//sort the terminal points of all ranges
		int min=1e6;//suppose minm range to dlt is this much
		int last=-1;//last terminal points
		int lastLeft=0;//last starting point out of many starting points for each given range
		int firstRight=2*n+1;//first finishing point
		for(int i=0;i<2*n;i++){   //calculate cmn range for each unique terminal point(use of last)
			//cout<<terpts[i].first<<"\n"; 
			if(last==terpts[i].first) nuCmnRng[nuCmnRng.size()-1]+=terpts[i].second;
			else nuCmnRng.push_back(terpts[i].second);
			last= terpts[i].first;
			//to find out last left and first right
			if(terpts[i].second==1) lastLeft=nuCmnRng.size()-1;
			if(terpts[i].second==-1&&firstRight>i) firstRight=nuCmnRng.size()-1;
		}

		//take cumalative sum and take min 	
		int m = nuCmnRng.size();
		//cout<<"m="<<m<<"\n";
		for(int  i=1;i<m;i++) nuCmnRng[i]+=nuCmnRng[i-1];
		//we want two *non empty* sets of range, thus start from first right and only go till last left
		for(int i=firstRight;i<lastLeft;i++) if(nuCmnRng[i]<min) min=nuCmnRng[i];

		if(min==1e6||n==1) cout<<-1<<"\n";
		else cout<<min<<"\n";
	}
return 0;
}
