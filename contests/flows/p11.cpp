//before doing this question attempt q p12
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using pi=pair<int,int>;
vector<vi> weight;
vector<vi> adj;
vector<vector<char> > grid;
vi par;
int f,mf;
const int INF =1000;
int x,y,p,n;


int ijToVertex(int i,int j){
  return y*i+j+1;
}
void graphModelling(){
  for(int i=0;i<x;i++){
    for(int j=0;j<y;j++){
      int v=ijToVertex(i,j);
      cin>>grid[i][j];
        if(grid[i][j]=='*'){
          adj[0].push_back(v);
          adj[v+n].push_back(0);
          weight[0][v]=1;

          adj[v].push_back(v+n);
          adj[v+n].push_back(v);// reverse edge having cap zero
          weight[v][v+n]=1;

        }
        if(grid[i][j]=='.'){
          adj[v].push_back(v+n);
          adj[v+n].push_back(v);
          weight[v][v+n]=1;
        }
        if(grid[i][j]=='@'){
          adj[v].push_back(v+n);
          adj[v+n].push_back(v);
          weight[v][v+n]=INF;

        }
        if(grid[i][j]=='#'){
          adj[v].push_back(v+n);
          adj[v+n].push_back(v);
          weight[v][v+n]=INF;

          adj[v+n].push_back(n);
          adj[n].push_back(v);
          weight[v+n][n]=p;
        }
        if(grid[i][j]!='~'){
          if(i&&grid[i-1][j]!='~'){
            adj[v+n].push_back(ijToVertex(i-1,j));
            adj[n+ijToVertex(i-1,j)].push_back(v);
            adj[ijToVertex(i-1,j)].push_back(v+n);
            adj[v].push_back(n+ijToVertex(i-1,j));
            weight[v+n][ijToVertex(i-1,j)]=INF;
            weight[n+ijToVertex(i-1,j)][v]=INF;

          }
          if(j&&grid[i][j-1]!='~'){
            adj[v+n].push_back(ijToVertex(i,j-1));
            adj[n+ijToVertex(i,j-1)].push_back(v);
            adj[ijToVertex(i,j-1)].push_back(v+n);
            adj[v].push_back(n+ijToVertex(i,j-1));
            weight[v+n][ijToVertex(i,j-1)]=INF;
            weight[n+ijToVertex(i,j-1)][v]=INF;

          }
        }
    }
  }
}

void augment(int u, int min_edge){
  if(u==0) {f=min_edge; return;}
  else if(par[u]!=-1){
    min_edge=min(min_edge,weight[par[u]][u]);
    augment(par[u],min_edge);
    weight[par[u]][u]-=f;
    weight[u][par[u]]+=f;
  }
}
void bfs(){
  mf=0;
  while(1){
    par.clear();
    par.assign(2*n,-1);
    f=0;
    vector<bool> visited;
    visited.assign(2*n,false);
    visited[0]=true;
    queue<int> q;
    q.push(0);
    while(!q.empty()){
      int u=q.front();
      q.pop();
      if(u==n) { break;}
      for(auto v:adj[u]){
        if(!visited[v]&&weight[u][v]>0){
          visited[v]=true;
          par[v]=u;
          q.push(v);
        }
      }
    }
    augment(n,INF);
    if(!f) break;
    mf+=f;
  }
  cout<<mf<<"\n";
}

int main(){
  while(cin>>x>>y>>p){
    n=x*y+1;
    adj.clear();
    adj.assign(2*n,vi());
    weight.clear();
    weight.assign(2*n,vi(2*n,0));
    grid.clear();
    grid.assign(x,vector< char >(y));

    graphModelling();

    bfs();

  }
}
//reverse edge from source or to the vertex is not necessary
