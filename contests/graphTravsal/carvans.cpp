//still getting wrong answer case 13
//approach is to keep updating minm distance from r along each path
//whenevver two paths merges we will do maxm if those minm distance
//and finally the distance at f will be answer
#include<bits/stdc++.h>
using namespace std;
using pii=pair <int,int> ;
using vi=vector<int> ;
vector<vi> adj;
vi p;
const int INF=1000000;
int n,m,s,f,r;

void bfs(int s,vector<int> &d) {

  p.assign(n,-1);
  p[s]=s;

  queue<int> q;
  q.push(s);
  d[s]=0;

  vector<bool> visited;
  visited.assign(n,false);
  visited[s]=true;
  while(!q.empty()){
    int u=q.front();
    q.pop();
    for(auto v:adj[u]){
      if(!visited[v]){
        visited[v]=true;
        d[v]=d[u]+1;
        q.push(v);
        p[v]=u;
      }
    }
  }
}

void Bfs(int s,vector<int> &distance_R) {
  //int ans=0;
  int  minm_dist_from_R_so_far,updated_minm_dist_from_R_so_far;
  vi ans;
  ans.assign(n,INF);

  p.assign(n,-1);
  p[s]=s;

  queue<int> q;
  q.push(s);
  ans[0]=distance_R[s];

  vi d;
  d.assign(n,INF);
  d[s]=0;

  vector<bool> visited;
  visited.assign(n,false);
  visited[s]=true;
  while(!q.empty()){
    int u=q.front();
    q.pop();
    //if(u==f) break;
    for(auto v:adj[u]){
      //if(v==f) cout<<u+1<<" "<<v+1<<" "<<d[f]<<" \n";
      if(d[v]==d[u]+1){
        //cout<<u+1<<" asdfa"<<v+1<<" \n";
        int x=min(distance_R[v],ans[u]);
        ans[v]=max(x,ans[v]);
      }
      if(!visited[v]){
        visited[v]=true;
        d[v]=d[u]+1;
        //cout<<u+1<<" "<<v+1<<" \n";
        //cout<<minm_dist_from_R_so_far<<" "<<distance_R[v]<<"\n";
        ans[v]=min(distance_R[v],ans[u]);
        //cout<<updated_minm_dist_from_R_so_far<<"\n";
        q.push(v);
        p[v]=u;
        //if(v==f)ans=updated_minm_dist_from_R_so_far;
      }
    }
  }
  cout<<ans[f];
}



int main(){

  cin>>n>>m;
  int u,v;
  adj.assign(n,vi());
  for(int i=0;i<m;i++){
    cin>>u>>v;
    --u,--v;
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  cin>>s>>f>>r;
  --s,--f,--r;

  vi distance_R;
  distance_R.assign(n,INF);
  bfs(r,distance_R);
  //for(int i=0;i<n;i++){
  //cout<<"distance_R[i]="<<distance_R[i]<<"\n";}

  vi distance_S;
  distance_S.assign(n,INF);
  Bfs(s,distance_R);
  return 0;

}
