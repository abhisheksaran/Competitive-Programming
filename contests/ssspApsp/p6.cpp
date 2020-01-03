//just sinple implementation of dijkstra

#include<iostream>
#include<utility>
#include<vector>
#include <queue>
#include<set>
#include<algorithm>

using namespace std;
typedef pair <int,int> pii;

int dijkstra(vector< pii > adj[], int u,int n)
{

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

    for(auto edge:adj[x])
    {
      int vertex=edge.first;
      int w=edge.second;
      //if(vertex==x&&d[vertex]==0)
      if(d[vertex]>d[x]+w)
      {
        q.erase({d[vertex],vertex});
        d[vertex]=d[x]+w;
        q.insert({d[vertex],vertex});
      }
    }
  }
  // there exist no path if parent of a vertex = -1 ie d[vertex]= INF

int max=-1;
int count=0;
for(int i=0;i<n;i++)
{
  if(d[i]>max&&d[i]!=INF)
  {
    max=d[i];
    count=1;
  }
  else if(d[i]==max) count++;
}

cout<<max<<" "<<count<<"\n";

}

int main()
{

  int n,m,u,v,w,Q,q;
  scanf("%d %d %d",&n,&m,&Q );
  vector<pii> adj[n];
  for(int i=0;i<m;i++)
  {
    scanf("%d %d %d",&u,&v,&w);
    adj[u].push_back({v,w});
    adj[v].push_back({u,w});
  }

  for(int i=0;i<Q;i++)
  {
    scanf("%d",&q);
  //x   cout<<q<<"\n";
    dijkstra(adj,q,n);
  }
  return 0;
}
