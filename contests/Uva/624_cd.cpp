#include<bits/stdc++.h>
using namespace std;
vector<int> cd;
int ans=0;
int setOftracks;

void printTracks(int n){
  for(int j=0;j<n;j++){
    if(setOftracks&(1<<j))
    {
      cout<<cd[j]<<" ";
    }
  }
}

void solve(int n,int s){
  ans =0;
  for(int i=0;i<(1<<n);i++){
    int sum=0;
    for(int j=0;j<n;j++){
      if(i&(1<<j))
      {
        sum=sum+cd[j];
        if(sum>s) break;
      }
    }
  if(sum==s){ ans=sum;setOftracks=i; break;}
  if(sum<s&&sum>ans){ans=sum;setOftracks=i; }
  }
  //cout<<setOftracks<<"\n"
  printTracks(n);
}



int main(){
  int s,n;
  while(cin>>s){
    cin>>n;
    cd.clear();
    for(int i=0;i<n;i++){
      int track;
      cin>>track;
      cd.push_back(track);
    }
    solve(n,s);
    cout<<"sum:"<<ans<<"\n";
  }
}
