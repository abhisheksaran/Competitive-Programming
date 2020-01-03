#include<iostream>
#include<vector>
#include<set>
#include<utility>
#include<algorithm>
#include<numeric>
using namespace std;
typedef pair <int,int> pii;
const long long INF = 10000000000000;
void dijkstra(vector<pii> adj[],int c,int n,int k)
{
  vector<long long> d;
  d.assign(n,INF);
  d[k]=0;


  set<pii> q;
  q.insert({0,k});

  int v;
  while(!q.empty())
  {
    v=q.begin()->second;
    q.erase(q.begin());


    if(v==c-1) break;

    for(auto edge:adj[v])
    {
      int u=edge.first;
      int w=edge.second;
      //if once it comes to the path it shoulf
      if(v<c)
      {
        if((u==v-1||u==v+1)&&d[u]>d[v]+w)
        {
          q.erase({d[u],u});
          d[u]=d[v]+w;
          q.insert({d[u],u});
        }
      }

      else if(d[u]>d[v]+w)
      {
        q.erase({d[u],u});
        d[u]=d[v]+w;
        q.insert({d[u],u});
      }
    }

  }
  cout<<d[c-1]<<"\n";
  return;
}

int main()
{
  int n,m,c,k;
  int u,v,p;

  while((cin >> n >> m >> c >> k))
  {
    vector <pii> adj[n];
    if(n==0&&m==0&&c==0&&k==0) break;
    for(int i=0;i<m;i++){

      scanf("%d %d %d",&u,&v,&p );
      adj[u].push_back({v,p});
      adj[v].push_back({u,p});

      //cout<<u<<" "<<v<<"\n";
    }


    dijkstra(adj,c,n,k);
    //scanf("%d %d %d %d",&n,&m,&c,&k);
  }
  return 0;
}
