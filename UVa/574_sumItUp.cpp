#include<bits/stdc++.h>
using namespace std;
int t,n;
vector<int> num;
vector<int> currentSoln;
vector<int> recentSoln;
set<vector<int> > setOfSoln;

void printSoln(){
  set<vector<int> > :: reverse_iterator itr;
  for(itr=setOfSoln.rbegin();itr!=setOfSoln.rend();++itr){
    recentSoln=*itr;
    for(int j=0;j<recentSoln.size();j++){
      if(j>0) cout<<"+";
      cout<<recentSoln[j];
    }
    cout<<"\n";
  }
}

void solve(){
  for(int i=(1<<n)-1;i>=0;i--){
    int sum=0;
    currentSoln.clear();

    for(int j=0;j<n;j++){
      if(i&(1<<(n-1-j))){ sum+=num[j];currentSoln.push_back(num[j]);}
      if(sum>t) break;
    }
    if(sum==t) {setOfSoln.insert(currentSoln);}
  }
  if(setOfSoln.size()==0) cout<<"NONE\n";
  else printSoln();
}

int main(){

  while(cin>>t>>n){
    if(t==0&&n==0) break;
    cout<<"Sums of "<<t<<":\n";
    num.clear();
    setOfSoln.clear();
    for(int i=0;i<n;i++){
      int x;
      cin>>x;
      num.push_back(x);
    }
    solve();
  }
}
