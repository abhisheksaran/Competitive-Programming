//similar as p2
//first find mst
//find maxm length edge in the path from intial to target
//using dfs
#include<bits/stdc++.h>

using namespace std;
using vi= vector<int>;
using pii=pair<int,int >;

vector<bool> visited;
vector <vector<pii> > adj;
vi p,rankk;

void assign(int n)
{
  rankk.assign(n,0);
  p.assign(n,0);
  for(int i=0;i<n;i++) p[i]=i;
}

int findSet(int i)
{ return (p[i]==i)? i:(p[i]=findSet(p[i]));}

bool isSameSet(int i,int j)
{return findSet(i)==findSet(j);}

void unionSet(int i,int j)
{
  if(!isSameSet(i,j)){
    int x=findSet(i), y=findSet(j);
    if(rankk[x]>rankk[y]) p[y]=x;
    else if(rankk[x]==rankk[y]) p[y]=x,rankk[x]++;
    else p[x]=y;
  }
}

struct edge{
  int u,v,w;
};
bool cmp(const edge& e1,const edge& e2){ return e1.w<e2.w;}

void kruskal(vector<edge> edges, int n)
{
  assign(n);
  for(edge e:edges){
    if(!isSameSet(e.u,e.v)){
      unionSet(e.u,e.v);
      adj[e.u].push_back(pii(e.v,e.w));
      adj[e.v].push_back(pii(e.u,e.w));
    }
  }
}

void dfs(int u,int v,int& Max){
  visited[u]=true;
  if(u==v) return;
  for(auto e:adj[u])
  {
    if(!visited[e.first]){
      dfs(e.first,v,Max);
      //if target got true when explring this edge(u->ad[u].first)
      //this means this edge will be in respective path
      //so take maxm of all such edges ie.
      //maxm length edge from the path from start to aim
      if(visited[v])
      {Max=max(Max,e.second);
        break;}
    }
  }
  return;
}

int main()
{
  int t,n,m,w,q,u,v,q1,q2;
  scanf("%d",&t);
  for(int i=0;i<t;i++)
  {
    cout<<"Case "<<i+1<<"\n";
    vector<edge> edges;
    edges.clear();
    scanf("%d %d",&n,&m);
    for(int j=0;j<m;j++){
        scanf("%d %d %d",&u,&v,&w );
        edges.push_back({--u,--v,w});
      }
    sort(edges.begin(),edges.end(),cmp);
    adj.clear();
    //intialiation of adj list of mst
    adj.assign(n,vector<pii>());
    kruskal(edges,n);

    scanf("%d",&q);
    for(int j=0;j<q;j++){
      scanf("%d %d",&q1,&q2);
      int Max=0;
      visited.assign(n,false);
      dfs(--q1,--q2,Max);
      cout<<Max<<"\n";
      }
    cout<<"\n";
    }

    return 0;
}
