#include<bits/stdc++.h>
using namespace std;
int n;
vector<long > a;
vector<long> b;
vector<long> c;
vector<vector<long> > happiness ;
long mx(long x,long y){
	return (x>y) ? x:y ;
}

long solve(int i,int last){
	if(i==0) return happiness [i][last];
	else if(happiness[i][last]!=-1) return happiness [i][last];
	else{
		if(last==0){
			happiness[i][0]=max(b[i]+solve(i-1,1),c[i]+solve(i-1,2));
		}
		else if(last==1){
			happiness[i][1]=max(a[i]+solve(i-1,0),c[i]+solve(i-1,2));
		}
		else if(last==2){
			happiness[i][2]=max(b[i]+solve(i-1,1),a[i]+solve(i-1,0));
		}

		return happiness[i][last];
	}



}


	
int main(){
	cin>>n;
	a.assign(n,0);
	b.assign(n,0);
	c.assign(n,0);
	for(int i=0;i<n;i++){
		cin>>a[i];
		cin>>b[i];
		cin>>c[i];
	}
	happiness.assign(n,vector<long>(3,-1));
	happiness[0][0]=max(b[0], c[0]);
	happiness[0][1]=max(c[0], a[0]);
	happiness[0][2]=max(a[0], b[0]);

	cout<<max(solve(n-1,0),max(solve(n-1,1),solve(n-1,2)));

	return 0;
}




