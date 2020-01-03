#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,n2=0;
  while(cin>>n){
    if(n==0) break;
    if(n2) cout<<"\n";
    int arr[n];
    for(int i=0;i<n;i++){
      cin>>arr[i];
    }
    int a,b,c,d,e,f;
    for(a=0;a<n-5;a++){
      for(b=a+1;b<n-4;b++){
        for(c=b+1;c<n-3;c++){
          for(d=c+1;d<n-2;d++){
            for(e=d+1;e<n-1;e++){
              for(f=e+1;f<n;f++){
                cout<<arr[a]<<" "<<arr[b]<<" "<<arr[c]<<" "<<arr[d]<<" "<<arr[e]<<" "<<arr[f]<<"\n";
              }
            }
          }
        }
      }
    }
    n2=n;
  }
}
