#include<bits/stdc++.h>
using namespace std;
//struct triple{
//  int x,y,z;
//};

int main(){
  int n;
  int arr[43];
  for(int i=0;i<=20;i++){
    arr[i]=i;
  }
  arr[21]=21,arr[22]=22,arr[23]=24,arr[24]=26,arr[25]=27,arr[26]=28,arr[27]=30,arr[28]=32,arr[29]=33,arr[30]=34,arr[31]=36,arr[32]=38,arr[33]=39;
  arr[34]=40,arr[35]=42,arr[36]=45,arr[37]=48,arr[38]=50,arr[39]=51,arr[40]=54,arr[41]=57,arr[42]=60;
  while(1){
    cin>>n;
    if(n<=0) break;
    int a,b,c;
    int perm=0;
    int comb=0;
    set< tuple<int,int,int> > combination;

    for(a=0;a<=42;a++){
      if(n>180) break;
      for(b=0;b<43;b++){
        for(c=0;c<43;c++){
          if(arr[a]+arr[b]+arr[c]==n) {perm++;}
          if(arr[a]+arr[b]+arr[c]==n&&arr[a]>=arr[b]&&arr[b]>=arr[c]) combination.insert({arr[a],arr[b],arr[c]});
        }
      }
    }
    if(combination.size()==0) cout<<"THE SCORE OF "<<n<<" CANNOT BE MADE WITH THREE DARTS.\n";
    else{
      cout<<"NUMBER OF COMBINATIONS THAT SCORES "<<n<<" IS "<<combination.size()<<".\n";
      cout<<"NUMBER OF PERMUTATIONS THAT SCORES "<<n<<" IS "<<perm<<".\n";
    }
    for(int i=0;i<70;i++){cout<<'*';}
    cout<<"\n";
  }
  cout<<"END OF OUTPUT\n";
  return 0;
}
