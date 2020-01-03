#include<bits/stdc++.h>
using namespace std;

int main(){
  int f,r;
  while(cin>>f>>r){
    vector<double> drive;
    if(f==0) break;
    //cin>>r;
    double arrf[f];
    double arrr[r];
    for(int i=0;i<f;i++){
      cin>>arrf[i];
    }

    for(int i=0;i<r;i++){
      cin>>arrr[i];
      for(int j=0;j<f;j++){
        drive.push_back((arrr[i]/arrf[j]));
      }
    }
    double mx=0;
    sort(drive.begin(),drive.end());
    for(int i=1;i<drive.size();i++){
      //cout<<drive[i]<<"\n";
      mx=max(mx,double(drive[i]/drive[i-1]));
    }
    cout<<fixed<<setprecision(2)<<mx<<"\n";
  }
}
