#include<bits/stdc++.h>
using namespace std;
using pii=pair<int,int>;
using vi=vector<int>;
const int INF=1000000;
vector<vector<pii> > adj;
vi d;
vector<bool> visited;


void dijkstra(int s){
  set<pii> q;
  q.insert({0,s});
  d[s]=0;
  while(!q.empty()){
    int u=q.begin()->second;
    q.erase(q.begin());
    for(auto e: adj[u]){
      int v=e.second;
      int w=e.first;
      if(!visited[v]&&d[v]>d[u]+w){
        q.erase({d[v],v});
        d[v]=d[u]+w;
        visited[v]=true;
        q.insert({d[v],v});
      }
    }
  }
}
void count(int clk)
{ int ans=0;
  for(int i=0;i<d.size();i++)
  {
    if(d[i]<=clk)ans++;
  }
  cout<<ans<<"\n";
  return;
}

int main(){
  int n,target,clk,m;
  int u,v,w;
  cin>>n>>target>>clk>>m;
  target--;
  adj.assign(n,vector<pii>());
  d.assign(n,INF);
  visited.assign(n,false);
  for(int i=0;i<m;i++){
    cin>>u>>v>>w;
    --u,--v;
    adj[u].push_back({w,v});
    adj[v].push_back({w,u});
  }
  dijkstra(target);
  count(clk);
}
