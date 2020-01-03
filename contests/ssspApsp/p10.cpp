#include<iostream>
#include<vector>
#include<set>
#include<vector>

using namespace std;
typedef pair<int,int > pii;
const long long INF = 10000000000000;
int dijkstra(vector<pii> adj[],int start, int dest,int n)
{
    vector<int> d;
    d.assign(n,INF);
    d[start]=0;

    set<pii>q;
    q.insert({0,start});
    while(!q.empty())
    {
      int u=q.begin()->first;
      q.erase(q.begin());

      for(auto edge:adj[u])
      {
        int v=edge.first;
        int w=wdge.second;
        if(d[v]>)
      }
    }

}

int main()
{
  int n,m,u,v,w,start,dest;
  while(cin>>n>>m)
  {
    if(n==0&&m==0) break;
    vector<pii> adj[n];
    cin>>start>>dest;
    for(int i=0;i<n;i++)
    {
      scanf("%d %d %d",&u,&v,&w );
      adj[u].push_back({v,w});
    }

    dijkstra(adj,start,dest,n);
  }
  return 0;
}
