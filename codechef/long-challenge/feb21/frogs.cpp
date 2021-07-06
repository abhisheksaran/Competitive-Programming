/* @author: saran
 * Git: https://github.com/abhisheksaran
 * LinkedIn: https://www.linkedin.com/in/abhishek-saran-2900b/
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		vector<int> w(n,0);
		vector<int> l(n,0);

		for(int j=0;j<n;j++)cin>>w[j]; 
		for(int j=0;j<n;j++)cin>>l[j];
		//map[i] = frog number at location i 
		map<int,int> location;
		for(int j=0;j<n;j++) location[j]=j;
		int ans = 0;
		int pans = -1;
		while(ans!=pans){
			pans = ans;
			
			for(int j=0;j<n;j++){
				for(int k=0;k<n;k++){
					if(j==k) continue;
					if(w[k] < w[j] && location[k] >= location[j]){
						int steps = (location[k]- location[j])/l[j] +1 ;
						ans += steps;
						location[j] += (steps*l[j]);
					}
				}
			}
		}
		cout<<ans<<"\n";
	}	

	return 0;
}
