#include<bits/stdc++.h>

using namespace std;
using vii=vector<int>;
vii p,Rank;
//implementation of ufds to check cycle
void assign(int n)
{
  Rank.assign(n,0);
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
long long kruskal(vector<edge> edges,int n, vector<edge>& edges_mst ){
  long long ans=0;
  assign(n);
  for(edge e:edges){
    int a=e.u;
    int b=e.v;
    long long c=e.w;
    if(!isSameSet(a,b)){unionSet(a,b),ans=ans+e.w;
    edges_mst.push_back({a,b,c});}
  }
  return ans;
}
//to find out second best mst
long long kruskal(vector<edge> edges,int n, edge E ){
  long long ans=0;
  int x=0;
  assign(n);
  for(edge e:edges){
    int a=e.u;
    int b=e.v;
    long long c=e.w;
    //if you didn't understand, refer cp3 second best mst
    if(!isSameSet(a,b)&&!(a==E.u&&b==E.v&&c==E.w)){unionSet(a,b),ans=ans+e.w,x++;}

  }
  if(x!=n-1) ans=1000000000000;
  return ans;//if mst can't be formed when we don't include edge E
  //ie number of edges is not equal to n-1
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
    vector<edge> edges;
    vector<edge>  edges_mst;
    scanf("%d %d",&n,&m);
    for(int j=0;j<m;j++){
      scanf("%d %d %lld ",&u,&v,&w);
      edges.push_back({--u,--v,w});
    }
    sort(edges.begin(),edges.end(),comp);
    //weight of mst
    long long mst=kruskal(edges,n,edges_mst);
    printf("%lld ",mst);
    long long second_mst=1000000000000;
    //take minm of all st such that it excudes a edge which is in mst
    //to get second best mst
    for(auto e:edges_mst){
      long long x=kruskal(edges,n,e);
      second_mst=min(second_mst,x);
    }
    printf("%lld\n",second_mst);
  }
  //cout<<"\n";
return 0;
}
//question is about getting mst and second best mst
