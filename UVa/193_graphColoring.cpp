//u didn't unserstand question right

#include<bits/stdc++.h>
using namespace std;
vector<vector<int> > adj;
int n,m;

void bfs(){
	vector<int>  coloring(n);
	vector<int> white;
	vector<int> black;
	vector<bool> visited;
	visited.assign(n,false);
	queue<int> q;
	q.push(0);
	visited[0]=true;
	coloring[0]=1;
	white.push_back(0);
	while(!q.empty()){
		int u=q.front();
		q.pop();
		for(auto v:adj[u]){
			if(!visited[v]){
				q.push(v);
				visited[v]=true;
				if(coloring[u]){
					coloring[v]=0;
					black.push_back(v);
				}
				else{
					coloring[v]=1;
					white.push_back(v);
				}


			}
		}
	}
	if(white.size()>black.size())
	{	
		sort(white.begin(),white.end());
		for(int i=0;i<white.size();i++){
			cout<<white[i]+1<<" ";
				
		}
	cout<<"\n";	
	}
	else{
		sort(black.begin(),black.end());
		for(int i=0;i<black.size();i++){
			cout<<black[i]+1<<" ";
				
		}
		cout<<"\n";
	}

}



	
int main(){
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		cin>>n>>m;
		adj.clear();
		adj.assign(n,vector<int>());
		for(int j=0;j<m;j++){
			int u,v;
			cin>>u>>v;
			--u,--v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		bfs();
	}


}
