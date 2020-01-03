#include<bits/stdc++.h>
using namespace std;
using pii=pair <int,int> ;
using vi=vector<int> ;

vi p,Rank;
void assign(int n){
  Rank.assign(n,0);
  p.assign(n,0);
  for(int i=0;i<n;i++) p[i]=i;
}
int findSet(int i){
  return (p[i]==i)? i:(p[i]=findSet(p[i]));}
bool isSameSet(int i,int j){
  return  (findSet(i)==findSet(j));}
void unionSet(int i,int j){
  if(!isSameSet(i,j)){
    int x=findSet(i),y=findSet(j);
    if(Rank[x]>Rank[y]) p[y]=x;
    else if(Rank[x]==Rank[y]) p[y]=x, Rank[x]++;
    else p[x]=y;
  }
}

struct edge{
  int u,v;
  long long w;
};

bool comp(const edge& e1, const edge& e2){
  return e1.w<e2.w;}

void kruskal(vector <edge> edges, int home,int n){
  assign(n);
  long long ans=0;
  for(edge e : edges){
    int u=e.u;
    int v=e.v;
    long long w=e.w;
    if(!isSameSet(u,v)){unionSet(u,v),ans+=w;}
  }
  for(int i=0;i<n;i++){
    if(!isSameSet(home,i)){
      cout<<"Impossible\n";
      return;
    }
  }
  cout<<ans<<"\n";
  return ;

}
int main()
{
  int n,m;
  while(cin>>n>>m){
    vector<edge> edges;
    edges.clear();
    map<string,int> cities;
    cities.clear();
      if(n==0&&m==0) break;
      for(int  i=0;i<n;i++){
        string s;
        cin>>s;
        cities.insert({s,i});
        //cout<<s<<"\n";
      }
      for(int i=0;i<m;i++){
        string s1,s2;
        long long w;
        cin>>s1>>s2>>w;
        edges.push_back({cities[s1],cities[s2],w});
        //cout<<cities[s1]<<" "<<cities[s2]<<" "<<w<<"\n";
      }
      sort(edges.begin(),edges.end(),comp);
      string s;
      cin>>s;
      kruskal(edges,cities[s],n);

  }
}
//simple kruskal
//use map to number cities
