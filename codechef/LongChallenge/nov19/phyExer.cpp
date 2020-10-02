//very easy question
//may not havve oberved the constants, each n, m and k upto 10^3
//preacalculate c from each of a and b in time complexity (m*k+n*k)* log(10^18);
//can check for each n*m possibilities in time complexity (m*n) * log(10^18)
//thus total time complexity= (n*m+n*k+m*k) *log (10^18);

#include<bits/stdc++.h>
using namespace std;
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int x,y;
		cin>>x>>y;
		int n,m,k;
		cin>>n>>m>>k;
		vector<long> nx(n,0);
		vector<long> ny(n,0);
		vector<long> mx(m,0);		
		vector<long> my(m,0);	
		vector<long> kx(k,0);
		vector<long> ky(k,0);	
		//input 
		for(int j=0;j<n;j++) cin>>nx[j]>>ny[j];		
		for(int j=0;j<m;j++) cin>>mx[j]>>my[j];		
		for(int j=0;j<k;j++) cin>>kx[j]>>ky[j];		
		//precalculate best c for each a
		long double inf= 1e18;
		long double dist;
		long double ans=inf ;
		vector<long double> bestN2K(n,inf);
		for(int j=0;j<n;j++){
			for(int l=0;l<k;l++){
				dist=sqrt(pow((nx[j]-kx[l]),2)+pow((ny[j]-ky[l]),2));
				bestN2K[j]=min(dist,bestN2K[j]);
			}
		}	
			
		//precalculate best c for each b
		vector<long double> bestM2K(m,inf);
		for(int j=0;j<m;j++){
			for(int l=0;l<k;l++){
				dist=sqrt(pow((mx[j]-kx[l]),2)+pow((my[j]-ky[l]),2));
				bestM2K[j]=min(dist,bestM2K[j]);
			}
		}	
		
		//for each combination of a and b;
		for(int j=0;j<n;j++){
			for(int l=0;l<m;l++){
				dist=sqrt(pow((x-mx[l]),2)+pow((y-my[l]),2))+sqrt(pow((mx[l]-nx[j]),2)+pow((my[l]-ny[j]),2)) + bestN2K[j];
				dist=min(dist,sqrt(pow((x-nx[j]),2)+pow((y-ny[j]),2))+sqrt(pow((mx[l]-nx[j]),2)+pow((my[l]-ny[j]),2)) + bestM2K[l]);	
				ans =min(ans,dist);
			}
		}
		
		cout<<fixed<<setprecision(8)<<ans<<"\n";
	} 
return 0; 
}
