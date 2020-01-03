#include<bits/stdc++.h>
using namespace std;
int main(){
  int c,i,d,k,l;
  cin>>c;
  for(int j=0;j<c;j++){
    cin>>i;
    vector<int> pol(i+1,0);
    for(l=0;l<=i;l++){
      int x;
      cin>>x;
      pol[l]=x;
    }
    cin>>d>>k;
    int term=1;
    l=0;
    while(k>(l*(l+1)*d)/2){
      l++;
      term =l;
    }
    unsigned long long ans=0;
    for(l=0;l<=i;l++){
      ans+=(pol[l]*pow(term,l));
    }
    cout<<ans<<"\n";
  }
  return 0;
}
