#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<int> c(n,0);
	vector<int> b(n,0);
	//input
	for(int i=0;i<n;i++) cin>>c[i];
	for(int i=0;i<n;i++) cin>>b[i];
	//count how many times cost of bus is minm in bMinm and cost of car in cMinm
	int bMinm=0;
	int cMinm=0;
	long cost=0;//minm cost
	for(int i=0;i<n;i++) {
		if(c[i]>b[i]){
			bMinm++;
			cost+=b[i];
		}
		else {
			cMinm++;
			cost+=c[i];
		}
	}
	
	int diff;//difference between number of minm cost of car and bus should be either be 0 or 1
	vector<int> overcost;//you took all the minm and add it to cost but may be such cost will may have consecutive same way of travel, to determine this fact we have diff value
	if(bMinm<cMinm){ 
		diff=cMinm-bMinm;
		if(diff>1) {
			for(int i=0;i<n;i++){
				if(b[i]>=c[i]) overcost.push_back(-c[i]+b[i]);//we have to add some overcost of diff/2 minm difference destinations 
			}
		}
	}
	else{
		diff=bMinm-cMinm;
		if(diff>1) {
			for(int i=0;i<n;i++){
				if(b[i]<c[i]) overcost.push_back(-b[i]+c[i]);
			}
		}
	}
//	cout<<overcost.size()<<"\n";	
	sort(overcost.begin(),overcost.end());
	if(overcost.size()>0){
		for(int i=0;i<diff/2;i++){
//			cout<<overcost[i]<<"\n";
			cost+=overcost[i];
		}
	}

//	cout<<diff<<"\n";
	cout<<cost<<"\n";
	
	return 0;
}
	
//greedy algo


