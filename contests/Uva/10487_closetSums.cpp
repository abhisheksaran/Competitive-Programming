#include<bits/stdc++.h>
using namespace std;

int main(){
  int n,Q,q,sum,ans,count=0;
  int minm=1000000;ls

  while(cin>>n){
    if(n==0) break;
    count++;
    std::cout << "Case " <<count<<":"<< '\n';
    int a[n];
    for(int i=0;i<n;i++){
      cin>>a[i];
    }
    cin>>Q;
    for(int i=0;i<Q;i++){
      cin>>q;
      int temp=0;
      ans=a[0]+a[1];
      for(int j=0;j<n;j++){

        for(int k=j+1;k<n;k++){
          sum=a[j]+a[k];
          if(abs(sum-q)<abs(ans-q)) ans=sum;
        }
      }
      cout<<"Closest sum to "<<q<<" is "<<ans<<".\n";
    }
  }
  return 0;
}
