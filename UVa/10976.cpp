#include<bits/stdc++.h>
using namespace std;

int main(){
	int k;
	int count=0;
	vector<long > vectorX;
	vector<long >  vectorI;
	while(cin>>k){
		count=0;
	vectorX.clear();
	vectorI.clear();

		for(long i=k+1;i<=2*k;i++){
			long x=(k*i)/(i-k);
		
			if(x>0&&(x*i)/(x+i)==k) {
				count++;
				vectorX.push_back(x);
				vectorI.push_back(i);	

			}
		}
		cout<<count<<"\n";
		for(long i=0;i<count;i++){
		
			cout<<1<<'/'<<k<<" = "<<1<<'/'<<vectorX[i]<<" + "<<1<<'/'<<vectorI[i]<<"\n";
	
		}	
		
	}
return 0;
}

