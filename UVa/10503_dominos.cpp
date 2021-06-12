#include<bits/stdc++.h>
using namespace std;
using pi=pair<int,int>;
int n,m;
pi init;
pi dest;
vector<bool> selected;
vector<pi> pieces;
int cnt=0;
int ans=0;
void solve(int last){
	for(int i=0;i<pieces.size();i++)
	{
		//cout<<i<<"\n";

		if(!selected[i]&&last==pieces[i].first){
			//cout<<i<<"#\n";
			selected[(i/2)*2+1]=true;
			selected[(i/2)*2]=true;
			cnt++;
			//cout<<pieces[i].first<<" "<<pieces[i].second<<"\n";
			if(cnt==n){
				if(pieces[i].second==dest.first){
					ans=1;
					cout<<"YES\n";
				}
				else{
					selected[(i/2)*2+1]=false;
					selected[(i/2)*2]=false;
					cnt--;
					continue;
				}
			}
			solve(pieces[i].second);
			if(ans==1) return;
			selected[(i/2)*2+1]=false;
			selected[(i/2)*2]=false;
			cnt--;
		}

	}
	return;
	
}

int main(){
	while(cin>>n)
	{	if(n==0)break;
		cin>>m;
		ans=0;
		cnt=0;
		pieces.clear();
		selected.clear();
		selected.assign(m,false);
		int x,y;
		for(int i=0;i<m+2;i++){
			cin>>x>>y;
			if(i==0){
				init={x,y};
			}
			else if(i==1){
				dest={x,y};
			}
			
			else{
				pieces.push_back({x,y});
				pieces.push_back({y,x});

			}
		
		}
		solve(init.second);
		if(ans==0) cout<<"NO\n";
	}

}
//accepted
