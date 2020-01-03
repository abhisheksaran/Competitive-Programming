#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using pi=pair<int,int>;

vector<vi> weight;
vector<vi> adj;
vi p;
int f,mf;
const int INF=1000000;

void augment(int u,int min_edge){
  if(u==0){f=min_edge;return;}
  else if(p[u]!=-1){

    min_edge=min(weight[p[u]][u],min_edge);
      //cout<<u<<"\n";
    augment(p[u],min_edge);
    weight[p[u]][u]-=f;
    weight[u][p[u]]+=f;
  }
}

int main()
{
  int reg;
  while(cin>>reg){
    int n=reg*2+2;
    adj.clear();
    adj.assign(n,vi());
    weight.clear();
    weight.assign(n,vi(n,0));

    for(int i=1;i<=reg;i++){
      int cap;
      cin>>cap;
      adj[i].push_back(i+reg);
      adj[i+reg].push_back(i);
      weight[i][i+reg]=cap;
    }
    int m;
    cin>>m;
    for(int i=0;i<m;i++){
      int u,v,w;
      cin>>u>>v>>w;
      adj[reg+u].push_back(v);
      adj[v].push_back(reg+u);
      weight[reg+u][v]=w;
    }
    int b,d;
    cin>>b>>d;
    for(int i=0;i<b;i++){
      int x;
      cin>>x;
      adj[0].push_back(x);
      adj[x].push_back(0);
      weight[0][x]=INF;
    }
    for(int i=0;i<d;i++){
      int x;
      cin>>x;
      adj[n-1].push_back(x+reg);
      adj[x+reg].push_back(n-1);
      weight[x+reg][n-1]=INF;
    }

    //bfs
    mf=0;
    while(1){
      f=0;
      p.clear();
      p.assign(n,-1);
      vector<bool>  visited;
      visited.assign(n,false);
      visited[0]=true;
      queue<int> q;
      q.push(0);
      while(!q.empty()){
        int u=q.front();
        q.pop();
        for(auto v:adj[u]){
          if(!visited[v]&&weight[u][v]>0){
            visited[v]=true;
            p[v]=u;
            //cout<<u<<" "<<v<<" "<<weight[u][v]<<"\n";
            q.push(v);
          }
        }
      }
      augment(n-1,INF);
      if(f==0) break;
      mf+=f;
    }

    cout<<mf<<"\n";

  }
}
