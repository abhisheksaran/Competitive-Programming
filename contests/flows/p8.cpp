#include<bits/stdc++.h>
using namespace std;
using vi=vector<int>;
using pi=pair<int,int>;
vector<vector<string>> name;
int f,mf;
vector<vi> adj;
vector<vi> weight;
vi par;
vi assignment;

void augment(int u)
{
  if(u==0){ f=1; return;}
  else if(par[u]!=-1){
    augment(par[u]);
    weight[par[u]][u]-=f;
    weight[u][par[u]]+=f;
    assignment[par[u]]=u;

  }
}
int main()
{ int t;
  cin>>t;
  for(int i=0;i<t;i++){
    int p;
    cin>>p;
    int n=2*p+2;
    assignment.clear();
    name.clear();
    name.assign(26,vector<string>(26));
    adj.clear();
    weight.clear();
    assignment.assign(n,-1);
    adj.assign(n,vi());
    weight.assign(n,vi(n,0));
    for(int j=1;j<=p;j++)
    {
      int no_poss_names;
      cin>>no_poss_names;
      for(int k=0;k<no_poss_names;k++)
      {
        locale loc;
        string s;
        cin>>s;

        s[0]=toupper(s[0],loc);
        int x=int(s[0])-65+1;
        if(x<=p){
          //cout<<s<<" "<<x;
          adj[x].push_back(p+j);
          adj[p+j].push_back(x);
          //cout<<x<<" "<<p+j<<"\n";
          weight[x][p+j]=1,weight[p+j][x]=0;
          name[j-1][x-1]=s;
        }
        //cout<<" ";
      }
      //cout<<"\n";
      adj[p+j].push_back(n-1);
      adj[n-1].push_back(p+j);
      weight[p+j][n-1]=1;
      weight[n-1][p+j]=0;

      adj[0].push_back(j);
      adj[j].push_back(0);
      weight[0][j]=1,weight[j][0]=0;

    }
    mf=0;
    while(1){
      f=0;
      par.clear();
      par.assign(n,-1);
      vector<bool> visited;
      visited.assign(n,false);
      visited[0]=true;
      queue<int> q;
      q.push(0);
      while(!q.empty()){
        int u=q.front();
        q.pop();
        if(u==n-1) break;
        for(auto v:adj[u]){
          if(!visited[v]&&weight[u][v]>0)
          {
            visited[v]=true;
            par[v]=u;
            q.push(v);
            //cout<<u<<" "<<v<<"\n";
          }
        }
      }
      augment(n-1);
      if(f==0) break;
      mf+=f;
    }
    //cout<<"mf="<<mf<<"\n";
    cout<<"Case #"<<i+1<<":\n";
    for(int i=1;i<=p;i++){
      int x=assignment[i];
      int y=x-p-1;
      //cout<<x<<" "<<y<<"\n";
      string str=name[y][i-1];
      locale loc;
      for(int i=0;i<str.length();i++){
       if(i==0) cout<<toupper(str[i],loc);
        else cout<<tolower(str[i],loc);
      }
      cout<<"\n";
    }
  }
  return 0;
}

//use a extra 2d vector "name" to store the names by problem number starting from 0
//find max flow in a bipartitie graph of p and p where p is number of problem.
// and write down coresponding flow network
