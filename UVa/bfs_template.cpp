#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
//#define for(j, i,n) for(j=i;j<n;j++) 
vector<vi> adjList;
vi dist;
const int INF=1e6;
void bfs(int s){
	queue<int> q;
	dist[s]=0;
	q.push(s);
	while(!q.empty()){
	int u=q.front();
	q.pop();
//	cout<<u<<"\n";
	for(auto v: adjList[u]){
		if(dist[v]==INF){
			dist[v]=dist[u]+1;
			q.push(v);	
		}
	}
	}
}

int main(){
	int n,m,u,v,i;
	cin>>n;
	cin>>m;
	adjList.assign(n,vi());
	dist.assign(n,INF);
	for(i=0;i<m;i++){
		cin>>u>>v;
		adjList[u].push_back(v);
	}
	bfs(5);
	for(i=0;i<n;i++) cout<<dist[i]<<"\n";
	return 0;
}
