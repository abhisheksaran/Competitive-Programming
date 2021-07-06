#include<bits/stdc++.h>

using namespace std;

int main(){
	int t;
	cin>>t;
	long long sum=0;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		vector<int> a(4,0);
		vector<int>b(4,0);
		vector<int> c(4,0);
		vector<int> d(4,0);
		for(int j=0;j<n;j++){
			char ch;
			int x;
			cin>>ch>>x;
			if(ch=='A') a[(x/3)-1]++;
			if(ch=='B') b[(x/3)-1]++;
			if(ch=='C') c[(x/3)-1]++;
			if(ch=='D') d[(x/3)-1]++;
		}
		int maxm=-1e9;
		for(int p=0;p<4;p++){
			for(int q=0;q<4;q++){
				if(q==p) continue;
				for(int r=0;r<4;r++){
					if(r==q|r==p) continue;
					for(int s=0;s<4;s++){
						if(s==p|s==q|s==r) continue;
						vector<int> z(4,0);
						int pan=0;
						z[0]=a[p];
						z[1]=b[q];
						z[2]=c[r];
						z[3]=d[s];
						if(z[0]==0)pan++;
						if(z[1]==0)pan++;
						if(z[2]==0)pan++;
						if(z[3]==0)pan++;
						sort(z.begin(),z.end());
						int ans=z[0]*25+z[1]*50+z[2]*75+z[3]*100-pan*100;
						maxm=max(ans,maxm);
					}
				}
			}
		}
		cout<<maxm<<"\n";
		sum+=maxm;
	}
	cout<<sum<<"\n";
return 0;
}
