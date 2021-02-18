/* @author: saran
 * Git: https://github.com/abhisheksaran
 * LinkedIn: https://www.linkedin.com/in/abhishek-saran-2900b/
 */

#include<bits/stdc++.h>
using namespace std;

int main(){
	int n;
	cin>>n;
	//parent of each node, 0 to n-1 representation
	vector<int> p(n,-1);
	//adjList of directed graph
	vector<vector<int>> adjList(n,vector<int>());
	for(int i=1;i<n;i++){
		cin>>p[i];
		p[i]--;
		adjList[p[i]].push_back(i);
	}
	//number of children
	vector<int> nc(n,0);
	for(int i=0;i<n;i++) nc[i] = adjList[i].size();

	int Q;
	cin>>Q;
	vector<int> tasks(n,0);
	for(int i=0;i<Q;i++){
		int v, w;
		cin>>v>>w;
		v--;
		//if zero children
		if(nc[v]==0) tasks[v] += w;
		//else if tasks is divisble by number of childrens
		else if(w%nc[v]==0) tasks[v] += w;
		//else discard
	}
	int ans = 0;
	//bfs 
	queue<int> q;
	q.push(0);
	vector<bool> vis(n,false);
	vis[0] = true;

	while(!q.empty()){
		int u = q.front();
		q.pop();

		int childrens = nc[u];
		if(childrens == 0) ans += tasks[u];
		else {
			for(auto v: adjList[u]){
				if(nc[v]==0) tasks[v] += (tasks[u]/childrens);
				else if((tasks[u]/childrens)%nc[v] == 0) tasks [v] += (tasks[u]/childrens);

				q.push(v);
			}
		}
	}

	cout<<ans<<"\n";
	return 0;
}
