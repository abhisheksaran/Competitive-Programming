#include<bits/stdc++.h>
using namespace std;

vector<int> length;
int a;
int binSearch(int m,int n){
  if(m==n){
    if(length[m]==a) return m;
    else return -1;
  }
  int x=(m+n)/2;
  int ans=binSearch(m,x);
  if(ans==-1) ans=binSearch(x+1,n);

  return ans;
}


int main(){
  int t,n,x,p;
  cin>>t;
  for(int i=0;i<t;i++){
    cin>>n;
    cin>>p;
    length.clear();
    for(int j=0;j<p;j++){
      cin>>x;
      length.push_back(x);
    }
    sort(length.begin(),length.end());
    for(int j=p-1;j>=0;j--){
      x=length[j];
      a=n-x;
      if(x<floor(n/2)){
        cout<<"NO1\n";
        break;
      }
      int ans=binSearch(0,j);
      if(ans!=-1){
        cout<<"YES\n";
        break;
      }
      if(j==0){
        cout<<"NO2\n";
        break;
      }
    }
  }
}
