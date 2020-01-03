#include<bits/stdc++.h>
using namespace std;

int s,t,mf,f;
using vi=vector<int>;
using pi=pair<int,int>;
vector<vi> weight;
vector<vi> adj;
vi parent;
vector<vi> assignment;
int child;

void augment(int u,int n)
{
  if(u==0) {
    f=1;

    //assignment[parent[parent[n-1]]].push_back(parent[n-1]);
    //cout<<parent[0]<<" "<<parent[parent[0]]<<"\n";
    return;}
  else if(parent[u]!=-1){
    //if(parent[u]==0)assignment[u].push_back(child);
    child=u;
    augment(parent[u], n);
    weight[parent[u]][u]-=f;
    weight[u][parent[u]]+=f;
    if(f==1&&parent[u]<u&&parent[u]!=0&&u!=n-1){
      assignment[parent[u]].push_back(u);
    }
    if(parent[u]>u){
      assignment[u].erase(remove(assignment[u].begin(),assignment[u].end(),parent[u]));
    }
  }
}

int main(){
    int p,c,n;

    while(cin>>c>>p){
      int totalQ=0;
      if(c==0&&p==0) break;
      n=c+p+2;
      weight.clear();
      weight.assign(n,vector<int>(n,0));
      adj.clear();
      adj.assign(n,vector<int>());
      for(int i=1;i<=c;i++){
        int no_prob_cat_i;
        cin>>no_prob_cat_i;
        adj[0].push_back(i);
        weight[0][i]=no_prob_cat_i;
        adj[i].push_back(0);
        weight[i][0]=0;
        totalQ+=no_prob_cat_i;
        //cout<<i<<" "<<0<<"\n ";
      }
      for(int i=c+1;i<=c+p;i++){
        int no_cat_prob_i;
        cin>>no_cat_prob_i;
        for(int j=0;j<no_cat_prob_i;j++){
          int cat;
          cin>>cat;
          adj[cat].push_back(i);
          weight[cat][i]=1;
          adj[i].push_back(cat);
          weight[i][cat]=0;
          //cout<<i<<" "<<cat<<"\n";
        }
        adj[i].push_back(n-1);
        weight[i][n-1]=1;
        adj[n-1].push_back(i);
        weight[n-1][i]=0;
      }


      mf=0;
      assignment.clear();
      assignment.assign(c+1,vector<int>());
      while(1){
        f=0;
        parent.assign(n,-1);
        vector<bool> visited;
        visited.assign(n,false);
        visited[0]=true;
        queue<int> q;
        q.push(0);
        while(!q.empty()){
          int u=q.front();q.pop();
          //cout<<"u="<<u<<"\n";
          if(u==n-1) break;
          for(auto v:adj[u])
          {
            //cout<<u<<" hjk"<<v<<"\n";
            if(!visited[v]&&weight[u][v]>0){
              visited[v]=true;
              parent[v]=u;
              q.push(v);
            }
          }
        }

        augment(n-1,n);
        if(f==0) break;
        mf+=f;
      }
      //cout<<mf<<" "<<totalQ<<"\n";
      if(mf!=totalQ) cout<<"0\n";
      else if(mf==totalQ){
        cout<<"1\n";
        for(int i=1;i<=c;i++)
        {
          //cout<<assignment[i].size()<<" ";
          for(auto j:assignment[i])
          {
            cout<<j-c<<" ";
          }
          cout<<"\n";
        }
      }
    }
    return 0;
}
