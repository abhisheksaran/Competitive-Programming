/* @author: saran
 * Git: https://github.com/abhisheksaran
 * LinkedIn: https://www.linkedin.com/in/abhishek-saran-2900b/
 */

#include<bits/stdc++.h>
using namespace std;

string convertTo24(string m12, string format){
	if(format=="AM"){
		if(m12.substr(0,2)=="12") return "00"+m12.substr(2,3);
		else return m12;
	}
	else{
		if(m12.substr(0,2)=="12") return m12; 
		else{
			int x = stoi(m12.substr(0,2));
			x+=12;
			return to_string(x)+m12.substr(2,3);
		}
	}
}

int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		string mtime;
		string format;
		cin>>mtime>>format;
		mtime = convertTo24(mtime,format);
		//cnt of friends
		int cf ;
		cin>>cf;
		for(int j=0;j<cf;j++){
			string fstime;
			string fetime;
			cin>>fstime>>format;
			fstime = convertTo24(fstime,format);
			cin>>fetime>>format;
			fetime = convertTo24(fetime,format);
			if(mtime >= fstime && mtime <= fetime) cout<<1;
			else cout<<0;
		}
		cout<<"\n";

	}

	return 0;
}
