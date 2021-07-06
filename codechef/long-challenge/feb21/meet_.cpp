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
		string mtime;
		string format;
		cin>>mtime>>format;
		mtime = mtime+" "+format;
		cout<<mtime<<endl;
		//cnt of friends
		int cf ;
		cin>>cf;
		for(int j=0;j<cf;j++){
			string fstime;
			string fetime;
			cin>>fstime>>format;
			fstime = fstime+ " " + format;
			cin>>fetime>>format;
			fetime = fetime+ " " + format;
		//	cout<<fstime<<endl;
			if(mtime.substr(6,2)=="AM"){
				if(fstime.substr(6,2)=="PM") cout<<0;
				else if(fstime > mtime) cout<<0;
				else if(fetime.substr(6,2)=="PM") cout<<1;
				else if(fetime >= mtime) cout<<1;
				else cout<<0;
			}
			else{
				if(fstime.substr(6,2)=="PM"){
					if(fstime>mtime) cout<<0;
					else if(fetime>=mtime) cout<<1;
					else cout<<0;
				}
				else if(fetime.substr(6,2)=="AM") cout<<0;
				else if(fetime >= mtime) cout<<1;
				else cout<<0;
			}
		}
		cout<<"\n";

	}

	return 0;
}
