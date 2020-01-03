#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
vi p;
vector<vi> adj;
vector<vector<long long>> weight;
vector<bool> visited;
long long f,mf;
const long long INF=10000000000;

struct edge{
  int u,v;
};
vector<edge> min_edges;

void augment(int u,long long min_edge){
  if(u==0){f=min_edge;return;}
  else if(p[u]!=-1){
    min_edge=min(min_edge,weight[p[u]][u]);
    augment(p[u],min_edge);
    if(f==weight[p[u]][u]){
      min_edges.push_back({p[u],u});
      //cout<<p[u]+1<<" "<<u+1<<"\n";
    }
    weight[p[u]][u]-=f;
    weight[u][p[u]]+=f;
  }
}

void bfs(int n){
  mf=0;
  while(1){
    f=0;
    visited.assign(n,false);
    visited[0]=true;
    p.clear();
    p.assign(n,-1);
    queue<int> q;
    q.push(0);
    while(!q.empty()){
      int u=q.front();
      q.pop();
      if(u==1)break;
      for(auto v:adj[u]){
        if(!visited[v]&&weight[u][v]>0)
        {
          visited[v]=true;
          q.push(v);
          p[v]=u;
        }
      }
    }

    augment(1,INF);
    if(f==0)break;
    mf+=f;
    //cout<<f<<"\n";
  }
}

int main()
{
  int n,m;
  while(cin>>n>>m){
    if(n==0&&m==0) break;
    int u,v;
    long long w;
    adj.clear();
    weight.clear();
    adj.assign(n,vi());
    weight.assign(n,vector<long long>(n,0));
    for(int i=0;i<m;i++){
      cin>>u>>v>>w;
      u--;
      v--;
      adj[u].push_back(v);
      adj[v].push_back(u);
      weight[u][v]=w;
      weight[v][u]=w;
    }
    min_edges.clear();
    bfs(n);
    //bfs to find out reachable vertex from source
    bfs(n);
    //among all min_edges, those min_edges will be removed
    //for which one end is reachable but other not
    //ie edges which is going across min cut
    for(auto e:min_edges){
      int u=e.u;
      int v=e.v;
      if((visited[u]&&!visited[v])||(!visited[u]&&visited[v])){
        cout<<u+1<<" "<<v+1<<"\n";
      }
    }
    cout<<"\n";
  }
}
