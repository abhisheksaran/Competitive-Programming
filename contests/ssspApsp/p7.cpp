//just  a graph modification and implementation of dijkstra

#include<iostream>
#include<utility>
#include<vector>
#include <queue>
#include<set>
#include<algorithm>

using namespace std;
typedef pair <int,int> pii;

int dijkstra(vector< pii > adj[], int u, int v)
{
  int n=2*v+2;
  //just  see that INF is large enough then the maxm possible length of the path.
  const long long INF = 10000000000000;

  set<pii> q;
  q.insert({0,u});

  vector<long long> d;
  d.assign(n,INF);
  d[u]=0;

  while(!q.empty())
  {
    int x=q.begin()->second;
    q.erase(q.begin());

    if(x==v) break;

    for(auto edge:adj[x])
    {
      int vertex=edge.first;
      int w=edge.second;
      if(d[vertex]>d[x]+w)
      {
        q.erase({d[vertex],vertex});
        d[vertex]=d[x]+w;
        q.insert({d[vertex],vertex});
      }
    }
  }
  if(d[v]==INF) return -1;
  return d[v];
}



int main()
{
  int n,m;

  while(cin>>n>>m)
  {
    int u,v,w;
    vector<pii> adj[2*n];
    for(int i=0;i<m;i++)
    {
      scanf("%d %d %d",&u,&v,&w);
      u--;
      v--;
      //just this graph modification
      //Given a weighted graphG= (V, E, w),
      //suppose we only want to find a shortest path
      //with oddnumber of edges fromstot.
      //To do this, we can make a new graph G′.
      //For every vertexu in G,there are two vertices
      //uE and uO in G′:
      //these represent reaching the vertexu
      //through even and oddnumber of edges respectively.
      //For every edge(u, v)in G, there are two edges in G′
      //:(uE, vO)and(uO, vE). Both of these edges have
      //the same weight as the original.
      //Constructing this graph takes linear time O(V+E).
      //Then we can run shortest path algorithms from sE to tO.
      adj[u].push_back({v+n,w});
      adj[v+n].push_back({u,w});

      adj[u+n].push_back({v,w});
      adj[v].push_back({u+n,w});
    }

    cout<<dijkstra(adj,0,n-1)<<"\n";

  }
  return 0;
}
