/* @author: saran
 * Git: https://github.com/abhisheksaran
 * LinkedIn: https://www.linkedin.com/in/abhishek-saran-2900b/
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	int i;
	for(i=10;i>=1;i--){
		if(n%i==0) break;
	}
	cout<<i<<"\n";

	return 0;
}
