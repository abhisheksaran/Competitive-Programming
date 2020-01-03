#include<bits/stdc++.h>

using namespace std;
using vii=vector<int>;
vii p,Rank,d;
//implementation of ufds to check cycle
void assign(int n)
{
  Rank.assign(n,0);
  d.assign(n,0);
  p.assign(n,0);
  for(int i=0;i<n;i++) p[i]=i;
}
int findSet(int i){
  return (p[i]==i)? i:(p[i]=findSet(p[i]));}
bool isSameSet(int i,int j)
{return findSet(i)==findSet(j);}
void unionSet(int i,int j){
  if(!isSameSet(i,j)){
    int x=findSet(i),y=findSet(j);
    if(Rank[x]<Rank[y]) p[x]=y;
    else if(Rank[x]==Rank[y]) p[x]=y, Rank[y]++;
    else p[y]=x;
  }
}

struct edge{
  int u,v;
  long long w;
};
//comparator for sorting
bool comp(const edge& e1,const edge& e2)
{return e1.w<e2.w  ;}
//kruskal implementation using ds ufds
long long kruskal(vector<edge> adj,int n ){
  assign(n);
  for(edge e:adj){
    //edge e=adj.front(); this front and dlt edge creates TLE
    int a=e.u;
    int b=e.v;
    long long c=e.w;
    if(!isSameSet(a,b)){unionSet(a,b);}
    //will be true when the last edge of path from 0 to n-1
    //in max st will be found
    //and by max st this edge will be minm edge in the path
    if(isSameSet(0,n-1)) return -c;
    //adj.erase(adj.begin());
  }
  return -1;
}

int main()
{
  // added the two lines below for fast i/o
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  int t,n,m,u,v;
  long long w;
  scanf("%d",&t);
  for(int i=0;i<t;i++)
  {
    vector<edge> adj;
    scanf("%d %d",&n,&m);
    for(int j=0;j<m;j++){
      scanf("%d %d %lld ",&u,&v,&w);
      adj.push_back({--u,--v,-w});
    }
    sort(adj.begin(),adj.end(),comp);
    printf("%lld\n",kruskal(adj,n));
  }
return 0;
}
