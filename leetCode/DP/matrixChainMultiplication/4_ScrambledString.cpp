/*
 * @author: saran
 * Input: two strings 
 * Output: true if b is the scrambled string of a else false
 */
#include<bits/stdc++.h>
using namespace std;

bool helper(unordered_map<string,bool>& um, string a, string b, int n){
	if(n==1) return a == b ;
	
	if(um.find(a+" "+b)!=um.end()) return um[a+" "+b];
	bool ans = false;
	for(int k=1;k<n;k++){
		ans = ans or (helper(um,a.substr(0,k),b.substr(0,k),k) and  helper(um,a.substr(k,n-k),b.substr(k,n-k),n-k) );
		if(ans) return um[a+" "+b]=ans;
		//if(n==5)cout<<a.substr(0,k)<<" "<<b.substr(n-k,k)<<" "<<a.substr(k,n-k)<<" "<<b.substr(0,n-k)<<"\n";
		//if(n==5)cout<<helper(a.substr(0,k),b.substr(n-k,k),k)<<" "<<helper(a.substr(k,n-k),b.substr(0,n-k),n-k) <<"\n";
		ans = ans or (helper(um,a.substr(0,k),b.substr(n-k,k),k) and  helper(um,a.substr(k,n-k),b.substr(0,n-k),n-k) );
		if(ans) return um[a+" "+b]= ans;
	}
	//cout<<a<<" "<<b<<" "<<ans<<"\n";
	return um[a+" "+b]=ans;
	
}
int main(){
	int n;
	string a,b;
	cin>>a>>b;
	n = a.length();
	//recursive solution 
	//memoization - use unorderd map 
	unordered_map<string, bool > um;
	if(n!=b.length()) cout<<"No\n";
	else if(helper(um,a,b,n)) cout<<"Yes\n";
	else cout<<"No\n";

	return 0;
}
