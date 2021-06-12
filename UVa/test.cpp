#include<bits/stdc++.h>
using namespace std;
int x=0;
void soln(int j){
  int i=j+1;
  if(i==10) return;
  cout<<"bef i="<<i<<"\n";
  soln(i);
  cout<<"aft i="<<i<<"\n";
}

int main(){
  soln(0);
}
