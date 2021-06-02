#include<bits/stdc++.h>
using namespace std;
using pii<int,int>;
using vi=vector<int>;
using vii=vector<vi>;
const int INF =1000000;
int n,m;

vi lights;

void bfs()
{
  set<pii> q;
  q.insert({0,0});
  vi<vi> visited;
  vi.assign(n,vi(n,0));
  vi[0][0]=1;
  vi<vi> d;
  d.assign(n,vi(n,INF));
  d[0][0]=0;

  while(!q.empty()){
    int u=q.front()->second;
    q.erase(q.front());
    int i=q/m;
    int j=q%m;

    if(i&&!visited[i-1][j]){
      if(lights[i-1][j]==1) d[i-1][j]=min(d[i-1][j],d[i][j]);q.insert({d[i-1][j],j+(i-1)*m})

    }

  }
}

int main(){
  int k,i,j;
  cin>>n>>m>>k;
  lights.assign(n*m,0);
  for(int i=0;i<m;i++){
    cin>>i>>j;
    i--,j--;
    lights[i*m+j]=1;

  }
  bfs();

}
