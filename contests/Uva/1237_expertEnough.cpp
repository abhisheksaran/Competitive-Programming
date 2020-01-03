#include<bits/stdc++.h>
using namespace std;

int main(){
  int t,i,d,a,b;
  string str;
  cin>>t;
  for(i=0;i<t;i++){
    cin>>d;
    vector<string> maker(d);
    vector<int> l(d);
    vector<int> m(d);
    for(int j=0;j<d;j++){
      cin>>str>>a>>b;
      maker[j]=str;
      l[j]=a;
      m[j]=b;
    }
    int Q,q,ans,count;
    cin>>Q;
    for(int j=0;j<Q;j++){
      cin>>q;
      count=0;
      for(int p=0;p<d;p++){
        if(q>=l[p]&&q<=m[p]){
          ans=p;
          count++;
          if(count==2){
            cout<<"UNDETERMINED\n";
            break;
          }
        }
        //cout<<p<<"\n";
      }
      if(count==0) cout<<"UNDETERMINED\n";
      if(count==1) cout<<maker[ans]<<"\n";
    }
    if(i<t-1) cout<<"\n";
  }
  return 0;
}
