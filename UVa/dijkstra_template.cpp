#include<bits/stdc++.h>
using namespace std;
typedef pair<int,int> ii;
typedef vector<ii> vii;
typedef vector<int> vi;
//#define for(j, i,n) for(j=i;j<n;j++) 
vector<vii> adjList;
vi dist;
const int INF=1e6;
void dijkstra(int s){
	priority_queue<ii, vector<ii>, greater<ii> > pq;
	pq.push(ii(0,s));
	dist[s]=0;
	while(!pq.empty()){
	ii front=pq.top();
	pq.pop();
	int d=front.first;
	int u=front.second;
//	if(d>dist[u]) continue;//updating dpesn't change anything
//	cout<<u<<"\n";
	for(auto v: adjList[u]){
		if(dist[v.first]>dist[u]+v.second){
			dist[v.first]=dist[u]+v.second;
			pq.push(ii(dist[v.first],v.first));	
		}
	}
	}
}

int main(){
	int n,m,u,v,i,w;
	cin>>n;
	cin>>m;
	adjList.assign(n,vii());
	dist.assign(n,INF);
	for(i=0;i<m;i++){
		cin>>u>>v>>w;
		adjList[u].push_back(ii(v,w));
		adjList[v].push_back(ii(u,w));
	}
	dijkstra(0);
	for(i=0;i<n;i++) cout<<dist[i]<<"\n";
	return 0;
}
