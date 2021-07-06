/* @author: saran
 * Git: https://github.com/abhisheksaran
 * LinkedIn: https://www.linkedin.com/in/abhishek-saran-2900b/
 */

#include<bits/stdc++.h>
using namespace std;
int countCommonElements(set<string>s1, set<string>s2){
	if(s1.size()==0 || s2.size()==0) return 0;

	int cnt =0;
	auto it1 = s1.begin();
	auto it2 = s2.begin();
	while(it1 !=s1.end()&& it2 != s2.end()){
		if(*it1 == *it2){
			it1++;
			it2++;
			cnt++;
		}
		else if(*it1 > *it2) it2++;
		else it1++;
	}
	return cnt;

}
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		//store restOfTheWords in their corresponding first letter set
		vector<set<string>> sets(26);
		for(int j=0;j<n;j++){
			string s;
			cin>>s;
			sets[s[0]-'a'].insert(s.substr(1,s.size()-1));	
		}
		long ans =0;
		
		for(int j=0;j<26;j++){
			//if(sets[j].size() == 0) continue;
			vector<string> intersection;
			int temp = 0;
			for(int k=j+1;k<26;k++){
				//if(sets[k].size() == 0) continue;
				//auto it = set_intersection(sets[j].begin(), sets[j].end() , sets[k].begin(), sets[k].end(), intersection.begin());
				//cout<<j<<" "<<k<<" "<<intersection.size()<<"\n";	
				int cntCEs = countCommonElements(sets[j], sets[k]);
			//	cout<<cntCEs<<endl;
				temp += ((sets[j].size() - cntCEs)*(sets[k].size() - cntCEs))*2;
				
			}
			ans += temp;
		}
		cout<< ans<<"\n";
	}


	return 0;
}
