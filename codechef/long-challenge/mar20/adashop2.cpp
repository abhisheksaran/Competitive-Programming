#include<bits/stdc++.h>
using namespace std;
using pii= pair<int,int>; //defining pair of integers
int main(){
	int t;
	cin>>t;
	vector<pii> slnFromOrigin;
	slnFromOrigin.push_back({2,2});
	slnFromOrigin.push_back({3,1});
	slnFromOrigin.push_back({4,2});
	slnFromOrigin.push_back({1,5});
	slnFromOrigin.push_back({2,6});
	slnFromOrigin.push_back({7,1});
	slnFromOrigin.push_back({8,2});
	slnFromOrigin.push_back({3,7});
	slnFromOrigin.push_back({4,8});
	slnFromOrigin.push_back({7,5});
	slnFromOrigin.push_back({8,6});
	slnFromOrigin.push_back({7,7});
	slnFromOrigin.push_back({8,8});
	slnFromOrigin.push_back({7,7});
	slnFromOrigin.push_back({6,8});
	slnFromOrigin.push_back({5,7});
	slnFromOrigin.push_back({8,4});
	slnFromOrigin.push_back({7,3});
	slnFromOrigin.push_back({2,8});
	slnFromOrigin.push_back({1,7});
	slnFromOrigin.push_back({6,2});
	slnFromOrigin.push_back({5,1});
	slnFromOrigin.push_back({2,4});
	slnFromOrigin.push_back({1,3});
	for(int i=0;i<t;i++){
		int c,r;
		cin>>c>>r;
		int d=(c+r)/2;
		int movesFromOrigin=24;
		if (c==1 &&r==1) 
			cout<<movesFromOrigin<<"\n";
		else if(c==r) {
			cout<<movesFromOrigin+1<<"\n";
			cout<<1<<" "<<1<<"\n";
		}
		else{
			cout<<movesFromOrigin+2<<"\n";
			cout<<d<<" "<<d<<"\n";
			cout<<1<<" "<<1<<"\n";
		}

		for(int j=0;j<slnFromOrigin.size();j++){
			cout<<slnFromOrigin[j].first<<" "<<slnFromOrigin[j].second<<"\n";
		}
			
	}
	
	return 0;
}
