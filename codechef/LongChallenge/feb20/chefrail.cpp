#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n,m;
		cin>>n>>m;
		vector<long> a(n);
		vector<long> b(m);
		for(int j=0;j<n;j++) cin>>a[j];
		for(int j=0;j<m;j++) cin>>b[j];
		sort(a.begin(),a.end());
		sort(b.begin(),b.end());

		vector<int> sqa(100001,0);
		vector<int> sqb(100001,0);
		for(int x=0;x<n;x++){
			for(int y=x+1;y<n;y++){
				long q=a[x]*a[y];
				
				long double sr = sqrt(-q); 
 			//	cout<<sr<<" " << -q<<"\n";
  // If square root is an integer 
  				if((sr - floor(sr)) == 0) sqa[floor(sr)]++;
			}
		}
		
		for(int x=0;x<m;x++){
			for(int y=x+1;y<m;y++){
				long q=b[x]*b[y];
			
				long double sr = sqrt(-q); 
  
 	//			cout<<sr<<" " << -q<<"\n";
  // If square root is an integer 
  				if((sr - floor(sr)) == 0) 
				{	
					sqb[floor(sr)]++;
	//				cout<<sqb[floor(sr)]<<"\n";
				}
			}
	
		}	
		int ans=0;
		int temp=0;
		for(int j=0;j<m;j++)
		{	if(b[j]==0) temp=1;
			else ans=ans+(sqa[abs(b[j])]);
		}
		for(int j=0;j<n;j++)
		{
			if(a[j]==0) temp=2;
			else ans=ans+(sqb[abs(a[j])]);
	//		cout<<j<<" " <<ans<<"\n";	
		}
		if(temp==1) ans=ans+(n*(m-1));
		else if(temp==2) ans=ans+(m*(n-1));
		cout<<ans<<"\n";
	}
return 0;
}

		
	
