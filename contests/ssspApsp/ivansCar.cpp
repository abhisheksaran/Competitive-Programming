#include<iostream>
#include<utility>
#include<vector>
#include <queue>
#include<set>
#include<algorithm>

using namespace std;
typedef pair<int,int> pii;


int bfs0_1(vector<pii>adj[],int n,int u,int v)
{
  //intial d value are infinite exccept source
  // here d value means is number of gear change.
  const unsigned int INF = 1000000000;
  vector<int> d;
  d.assign(n,INF);
  d[u]=0;

  //initial there is no direction
  vector<int> direction;
  direction.assign(n,-1);

  // a deque to see which need to be explored first
  deque<int> q;
  q.push_front(u);
  while(!q.empty())
  {
    int vertex=q.front();
    q.pop_front();
    for(auto edge: adj[vertex])
    {
      int x=edge.first;
      int w=edge.second;
      //change will be 1 if edge type is changing ie downhill ot uphill or vice versa
      int change=0;
      if(direction[vertex]!=-1&&direction[vertex]!=w) change=1;
      //if vertex = source then  distance to it's adj will be zero as  says in q intila move doesn't matter
      if(direction[vertex]==-1) d[vertex]=0;
      //after adding change in distance if it can be relaxed
      if(d[x]>d[vertex]+change)
      {
        //direction of vertex will be updated
        direction[x]=w;
        d[x]=d[vertex]+change;
        // if change is 0 then it should be added to front so that it can get explored first
        if(change==0) q.push_front(x);
        else q.push_back(x);
      }
    }
  }
  // at last all distance will be minm in terms of gear changes
  return d[v];

}

int main()
{
  int n,m,u,v;
  scanf("%d %d",&n,&m);
  vector<pii> adj[n];
  for(int i=0;i<m;i++)
  //using bfs0-1 as adding extra 1 edge having weight 1
  {
    scanf("%d %d",&u,&v);
    u--;
    v--;
    adj[u].push_back({v,0});
    adj[v].push_back({u,1});
  }
  //cout<<adj[1][]
  scanf("%d %d",&u,&v);
  u--;
  v--;

  cout<<bfs0_1(adj,n,u,v);

}
