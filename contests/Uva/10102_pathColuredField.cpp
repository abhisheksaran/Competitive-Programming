#include<bits/stdc++.h>
using namespace std;

int main(){
  int m;
  while(cin>>m){
    vector<pair<int,int>> three;
    vector<pair<int,int>> one;
    for(int i=0;i<m;i++){
      string s;
      cin>>s;
      //cout<<s<<"\n";
      for(int j=0;j<m;j++){
        int x=int(s[j])-48;
        //cout<<x<<"\n";
        if(x==1) one.push_back({i,j});
        if(x==3) three.push_back({i,j});
      }
    }
    //cout<<one.size()<<" "<<three.size()<<"\n";
    int mx=0;
    for(int i=0;i<one.size();i++){
      int mn=1000000;
      for(int j=0;j<three.size();j++){
        mn=min(mn,abs(one[i].first-three[j].first)+abs(one[i].second-three[j].second));
        //cout<<mn<<"\n";
      }
      mx=max(mx,mn);
    }
    cout<<mx<<"\n";
  }
  return 0;
}
