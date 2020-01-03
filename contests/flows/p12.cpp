
//question is good to make your concept clear
#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using pi=pair<int,int >;
int mf,f;
vector<vi> adj;
vector<vi> weight;
vi p;
const int INF =1000000;
int m,w,n;

void augment(int u, int min_edge){
  if(u==0){f=min_edge;return ;}
  else if(p[u]!=-1){
    min_edge=min( min_edge, weight[p[u]][u]);
    augment(p[u],min_edge);
    weight[p[u]][u]-=f;
    weight[u][p[u]]+=f;
    }
}

void bfs(){

  mf=0;
  while(1){
    f=0;
    vector<bool> visited;
    visited.assign(n,false);
    visited[0]=true;
    p.clear();
    p.assign(n,-1);
    queue <int> q;
    q.push(0);
    while(!q.empty()){
      int u=q.front();
      q.pop();
      if(u==2*m+1)  break;
      for(auto v:adj[u]){
        if(!visited[v]&&weight[u][v]>0){
          visited[v]=true;
          q.push(v);
          p[v]=u;
        }
      }
    }

    augment(2*m+1,INF);
    if(f==0) break;
    mf+=f;
  }
  cout<<mf<<"\n";
}

void addEdges(){
for(int i=0;i<w;i++){
  int j,k,d;
  cin>>j>>k>>d;
  if(j==1&&k!=m){
    adj[j].push_back(k);
    adj[k+m].push_back(j);
    adj[k].push_back(j);//adding these two lines in each case took a very long time
    adj[j].push_back(k+m);//actually to digest the concept
    //reason explained in last case
    weight[j][k]=d;
    weight[k+m][j]=d;
  }
  else if(k==1&&j!=m){
    adj[k].push_back(j);
    adj[j+m].push_back(k);
    adj[j].push_back(k);
    adj[k].push_back(j+m);
    weight[k][j]=d;
    weight[j+m][k]=d;
  }
  else if(j!=1&&k==m){
    adj[j+m].push_back(k);
    adj[k].push_back(j);
    adj[k].push_back(j+m);
    adj[j].push_back(k);
    weight[j+m][k]=d;
    weight[k][j]=d;
  }
  else if(k!=1&&j==m){
    adj[k+m].push_back(j);
    adj[j].push_back(k);
    adj[j].push_back(k+m);
    adj[k].push_back(j);
    weight[k+m][j]=d;
    weight[j][k]=d;
  }
  else if((j==1&&k==m)||(j==m&&k==1)){
    adj[k].push_back(j);
    adj[j].push_back(k);

    weight[j][k]=d;
    weight[k][j]=d;
  }
  else{
    adj[j+m].push_back(k);//directed edge j to k
    adj[k+m].push_back(j);//directed edge k to j
    //above two lines is because
    //capacity in each direction(below two lines) is d
    //because it's a wire
    weight[j+m][k]=d;
    weight[k+m][j]=d;
    //next two lines is to allow reverse flow, initial cap is zero
    adj[k].push_back(j+m);
    adj[j].push_back(k+m);
  }
  adj[m].push_back(n-1);
  //adj[n-1].push_back(m);//still accepted
  weight[m][n-1]=INF;
}

}

int main()
{
  while(cin>>m>>w){
    if(m==0&&w==0) break;
    n=2*m+2;
    adj.clear();
    weight.clear();
    adj.assign(n,vi());
    weight.assign(n,vi(n,0));
    adj[0].push_back(1);
    //adj[1].push_back(0);//still accepted
    weight[0][1]=INF;
    for(int i=1;i<m-1;i++){
      int id, c;
      cin>>id>>c;
      id;
      adj[id].push_back(id+m);
      adj[id+m].push_back(id);
      weight[id][id+m]=c;
      //weight[id+m][id]=c;// still accepted
    }
    addEdges();
    bfs();
  }

return 0;
}
//source 0 is connected to machine 1
//and machine m is connected to target 2m+1
//vertex +edge capcity question
