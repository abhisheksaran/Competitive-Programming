#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
vi degree;
vector<vi> adj;
int n,m,u,v;
const int INF =1000000;

int bfs(int s,int t){
  vector<bool> visited;
  visited.assign(n,false);
  visited[s]=true;
  queue<int> q;
  q.push(s);
  vi d;
  d.assign(n,INF);
  d[s]=0;
  while(!q.empty()){
    int u=q.front();
    q.pop();
    for(auto v:adj[u]){
      if(!visited[v]){
        visited[v]=true;
        d[v]=d[u]+1;
        if(adj[v].size()>2)  q.push(v);
      }
    }
  }
  return d[t];
}
int main(){
  while(cin>>n>>m){
    if(!n&&!m) break;
    adj.clear();
    adj.assign(n,vi());
    degree.assign(n,0);
    for(int i=0;i<m;i++){
      cin>>u>>v;
      --u,--v;
      adj[u].push_back(v);
      adj[v].push_back(u);
      //degree[u]++,degree[v]++;

    }
    vi odd;
    int k=0;
    for(int i=0;i<n;i++){
      if(adj[i].size()==0) {cout<<"Poor Koorosh\n";k=1; break;}
      else if(adj[i].size()%2) odd.push_back(i);
    }
    if(k);
    else if(odd.size()==0) cout<<0<<"\n";
    else if(odd.size()==1) cout<<"Poor Koorosh\n";
    else if(odd.size()==2){
      if(adj[odd[0]].size()==1||adj[odd[1]].size()==1) cout<<"Poor Koorosh\n";
      else {
        int ans=bfs(odd[0],odd[1]);
        if(ans==INF) cout<<"Poor Koorosh\n";
        else cout<<ans<<"\n";
      }
    }
  }
}
