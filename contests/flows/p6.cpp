#include<bits/stdc++.h>
using namespace std;
using vi=vector<int> ;
using pi=pair<int,int>;
vector<vi> adj;
vector<vi> weight;
vi parent;
int mf,f;

void augment(int u){
  if(u==0){f=1;return;}
  else if(parent[u]!=-1){
    augment(parent[u]);
    weight[parent[u]][u]-=f;
    weight[u][parent[u]]+=f;
  }
}

int main(){
  int t;
  cin>>t;
  int n,m;
  map<string,int> mp;
  mp["S"]=1,mp["XS"]=2,mp["M"]=3,mp["L"]=4,mp["XL"]=5,mp["XXL"]=6;
  for(int i=0;i<t;i++){
    cin>>n>>m;
    int N=6+m+2;
    adj.clear();
    weight.clear();
    weight.assign(N,vector<int>(N,0));
    adj.assign(N,vector<int>());
    string s1,s2;
    for(int j=1;j<=6;j++){
      adj[0].push_back(j);
      adj[j].push_back(0);
      weight[0][j]=n/6;
      weight[j][0]=0;
    }
    for(int j=1;j<=m;j++){
      cin>>s1>>s2;
      int x=mp[s1];
      int y=mp[s2];
      adj[x].push_back(6+j);
      adj[6+j].push_back(x);
      adj[y].push_back(6+j);
      adj[6+j].push_back(y);
      weight[x][6+j]=1,weight[6+j][x]=0,weight[y][6+j]=1,weight[6+j][y]=0;
      adj[6+j].push_back(N-1);
      adj[N-1].push_back(6+j);
      weight[6+j][N-1]=1;
      weight[N-1][6+j]=0;
    }
     mf=0;
     while(1){
       f=0;
       vector<bool> visited;
       visited.assign(N,false);
       visited[0]=true;
       parent.assign(N,-1);
       queue<int> q;
       q.push(0);
       while(!q.empty()){
         int u=q.front();
         q.pop();
         for(auto v:adj[u]){
           if(!visited[v]&&weight[u][v]>0){
             visited[v]=true;
             parent[v]=u;
             q.push(v);
           }
         }
       }
       augment(N-1);
       if(f==0) break;
       mf+=f;
       //cout<<"f="<<f<<"\n";
     }
     //cout<<m<<" "<<mf<<"\n";
     if(mf==m) cout<<"YES\n";
     else cout<<"NO\n";
  }
  return 0;
}
