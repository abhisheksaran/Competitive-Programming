#include <iostream>
using namespace std;

int main() {
	//code
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
    	string s;
    	cin>>s;
    	string ans;
    	int n=s.size();
    	int j=n-1;
    	for(int i=n-1;i>=0;i--){
    	    if(i=='.'){
    	       ans.append(s.substr(i+1,j-i));
    	       ans.append(".");
    	       j=i-1;
    	    }
    	    cout<<ans<<"\n";
    	}
    	ans.append((s.substr(0,j+1)));
    	
    	cout<<ans<<"\n";
	}
	return 0;
}
