//simple kruskal
//have to display the mst edges
#include<bits/stdc++.h>
using namespace std;
using vi= vector<int>;
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
  int i=0;
  while(i<n-1)
  {
    edge e=edges.front();
    if(!isSameSet(e.u,e.v))
    {
      unionSet(e.u,e.v);
      //to print mst edge
      cout<<char(e.u+65)<<"-"<<char(e.v+65)<<" "<<e.w<<"\n";
      i++;
    }
    //rahter than doing this, you may have simply travelled the all edges
    //deleting the ele in vector incr complexity
    edges.erase(edges.begin());
  }

}

int main()
{
  int t,n,w;
  char c;
  scanf("%d",&t);
  for(int i=0;i<t;i++)
  {
    vector<edge> edges;
    scanf("%d",&n);
    for(int j=0;j<n;j++)
    {
      for(int k=0;k<n;k++)
      {
        cin>>w;
        if(k!=n-1) scanf("%c",&c);
        if(k>j&&w!=0) edges.push_back({j,k,w});
      }
    }
    sort(edges.begin(),edges.end(),cmp);
    cout<<"Case "<<i+1<<":\n";
    kruskal(edges,n);

  }
}
