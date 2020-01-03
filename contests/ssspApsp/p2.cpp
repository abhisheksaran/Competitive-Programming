//just sinple implementation of dijkstra

#include<iostream>
#include<utility>
#include<vector>
#include <queue>
#include<set>
#include<algorithm>

using namespace std;
typedef pair <int,int> pii;

void dijkstra(vector< pii > adj[], int u, int v)
{
  int n=v+1;
  //just  see that INF is large enough then the maxm possible length of the path.
  const long long INF = 10000000000000;

  set<pii> q;
  q.insert({0,u});

  vector<int> p;
  p.assign(n,-1);
  p[u]=u;

  vector<long long> d;
  d.assign(n,INF);
  d[u]=0;

  while(!q.empty())
  {
    int x=q.begin()->second;
    q.erase(q.begin());

    if(x==v) break;
    //cout<<x<<"\n";
    for(auto edge:adj[x])
    {
      int vertex=edge.first;
      int w=edge.second;
      if(d[vertex]>d[x]+w)
      {
        q.erase({d[vertex],vertex});
        d[vertex]=d[x]+w;
        p[vertex]=x;
        q.insert({d[vertex],vertex});
      }
    }
  }
  // there exist no path if parent of a vertex = -1 ie d[vertex]= INF
  if(p[v]==-1)
  {
    cout<<-1;
    return;
  }

  vector<int > path;
  for(int vertex=v;p[vertex]!=vertex;vertex=p[vertex])
  {
    path.push_back(vertex);
  }
  cout<<u+1<<" ";
  int k=path.size();
  for(int i=k-1;i>=0;i--) cout<<path[i]+1<<" ";
}

int main()
{

  int n,m,u,v,w;
  scanf("%d %d",&n,&m );
  vector<pii> adj[n];
  for(int i=0;i<m;i++)
  {
    scanf("%d %d %d",&u,&v,&w);
    u--;
    v--;

    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }

  dijkstra(adj,0,n-1);

  return 0;
}
