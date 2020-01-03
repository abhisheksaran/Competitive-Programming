#include<bits/stdc++.h>
using namespace std;
int d,s;
int ans;
void compltSearch(){
  ans=0;
  for(int i=0;i<(1<<12);i++){
    int sum=0;
    int sum5=0;
    vector<int> monthlyPosting;
    monthlyPosting.clear();
    for(int j=0;j<12;j++){
      if(i&(1<<j)){
        //cout<<j<<":1\n";
        sum=sum+s;
        monthlyPosting.push_back(s);
      }
      else{
        //cout<<j<<":0\n";
        sum=sum+d;
        monthlyPosting.push_back(d);
      }
      if(j==4){sum5=sum;}
      if(j>4)(sum5=sum5+monthlyPosting[j]-monthlyPosting[j-5]);
      if(j>=4&&sum5>=0)break;

    }

    if(sum>ans&&sum5<0) ans=sum;
  }
  if(ans==0) cout<<"Deficit\n";
  else cout<<ans<<"\n";
}
int main(){
  while(cin>>s){
    cin>>d;
    d=0-d;
    compltSearch();
  }
}
