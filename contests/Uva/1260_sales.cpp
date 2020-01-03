#include<bits/stdc++.h>
using namespace std;

int main(){
  int t,n,k,ans,key;
  cin>>t;
  for(int i=0;i<t;i++){
    cin>>n;
    int arr[n];
    for(int j=0;j<n;j++){
      cin>>arr[j];
    }
    ans=0;
    for(int j=1;j<n;j++){
      k=j-1;
      key=arr[j];
      while(k>=0&&arr[k]>key){

        arr[k+1]=arr[k];
        k--;
      }
      arr[k+1]=key;
      ans+=k+1;
    }
    cout<<ans<<"\n";
  }
  return 0;
}
