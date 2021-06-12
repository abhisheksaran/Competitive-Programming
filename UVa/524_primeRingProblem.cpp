#include<bits/stdc++.h>
using namespace std;
vector<int> sequence;
vector<bool> selected;
int n;
bool isPrime(int x){
  if(x==2||x==3||x==5||x==7||x==11||x==13||x==17||x==19||x==23||x==29||x==31) return true;
  else return false;
}

void printSoln(){
  for(int i=0;i<sequence.size();i++){
    cout<<sequence[i];
    if(i!=sequence.size()-1)cout<<" ";
  }
  cout<<"\n";
}

void solve(){
  int i;
  for(i=1;i<=n;i++){
    if(isPrime(sequence.back()+i)&&!selected[i]){
      sequence.push_back(i);
      selected[i]=true;

      if(sequence.size()==n){
        if(isPrime(sequence.front()+sequence.back())){
          printSoln();
          selected[sequence.back()]=false;
          sequence.pop_back();
          break;
        }
        else{
          selected[sequence.back()]=false;
          sequence.pop_back();
          break;
        }
      }
      solve();
    }
  }
  selected[sequence.back()]=false;
  sequence.pop_back();
  return;
}

int main(){
  int x=0;
  while(cin>>n){
    x++;
    if(x!=1)cout<<"\n";
    cout<<"Case "<<x<<":\n";
    sequence.clear();
    selected.assign(n+1,false);
    sequence.push_back(1);
    selected[1]=true;
    solve();

  }
}
