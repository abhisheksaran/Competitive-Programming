#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using pi=pair<int,int>;
vi p;
const int INF=10000;
int f,s,t,mf;
vector<vector<pi>> adj;
//int weight[100][100]={0};
//to store weights of edges
vector<vi> weight;
//find the min weight edge and augment
void augment(int v,int min_edge,int n){
  if(v==s) {f=min_edge; return;}//flow will be equal to min w wdge
  else if(p[v]!=-1){
    //traverse through the path till source to get minm weight edge
    min_edge=min(min_edge,weight[p[v]][v]);
    augment(p[v],min_edge,n);
    //decr cap of forward edge
    weight[p[v]][v]-=f;
    //incr cap of backward edge
    weight[v][p[v]]+=f;
  }

}


int main(){
  int n,c;
  int u,v,w;
  int network=0;
  while(cin>>n){
    if(n==0) break;
    network++;
    cin>>s>>t>>c;
    s--;
    t--;
    //weight[100][100]={0};
    weight.clear();//have to clear before next test case
    weight.resize(n,vector<int >(n,0));//this is how you intiallize a 2d vector
    //took a long time to find out, you can use 2d array but line 38 may cause  seg fault, why??
    adj.clear();
    adj.assign(n,vector<pi>());
    for(int i=0;i<c;i++){
      cin>>u>>v>>w;
      --u,--v;
      adj[u].push_back({v,w});
      adj[v].push_back({u,w});
      weight[u][v]+=w,weight[v][u]+=w;//multiple edges possible, add all , get total cap
    }
    //bfs to get a path
    mf=0;
    while(1){
      f=0;
      vector<bool> visited;
      visited.assign(n,false);
      visited[s]=true;
      p.clear();
      p.resize(n);
      p.assign(n,-1);
      queue<int> q;
      q.push(s);
      while(!q.empty()){
        int u=q.front();
        //cout<<u<<"\n";
        q.pop();
        if(u==t) break;
        for(auto e:adj[u]){
          int v=e.first;
          int w=e.second;
          if(!visited[v]&&weight[u][v]>0){
            //cout<<u<<" "<<v<<"\n";
            visited[v]=true;
            q.push(v);
            p[v]=u;//to retrive the  path from t back to s.
          }
        }
      }
      //find a path, now augment flow along this path
      augment(t,INF,n);
      if(f==0) break;//no more flow possible
      mf+=f;
    }
    cout<<"Network "<<network<<"\n";
    cout<<"The bandwidth is "<<mf<<"."<<"\n\n";
  }
return 0;
}


//took too much time to implement that how weight should be stored
//tried 2d array in main/ globally
//finally end up with global 2d vector
//never underestimate power of cplusplus.com
