#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,m;
		cin>>n>>m;
		vector<vector<int> > grid(n,vector<int>(m,0));
		queue<int> x;
		queue<int> y;
		for(int j=0;j<n;j++){
			for(int k=0;k<m;k++){
				cin>>grid[j][k];
				if(j>0&&k>0&&j<n-1&&k<m-1) {
					x.push(grid[j][k]);
					y.push(grid[j][k]);
				}
			}
		}
		int sum=n*m;
		int size=3;
		int mn=min(m,n);
		int z=x.size();
	//	cout<<z<<"\n";
		while(size<=mn){
			int bound=(size-1)/2;
			for(int a=0;a<z;a++){
				int p=x.front();
				int q=y.front();
	//			cout<<p<<" "<<q<<"\n";
				if((grid[p-bound][q]==grid[p+bound][q])&&(grid[p][q+bound]==grid[p][q-bound])) {
					sum++;
					x.pop();
					y.pop();
					if((p > bound)&&(q > bound)&&(p < (n-bound-1))&&(q < (m-bound-1))) {
						x.push(p);
						y.push(q);
					}

				}
			}
			size+=2;
			z=x.size();
			if(z==0) break;
		}
		cout<<sum<<"\n";



	}
	return 0;
}


