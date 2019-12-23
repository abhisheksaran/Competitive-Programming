#include<bits/stdc++.h>
using namespace std;

int main(){
	int n,sx,sy;
	cin>>n>>sx>>sy;
	int a=0,b=0,c=0,d=0;
	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		x=-sx+x;
		y=-sy+y;
	
		if(y>=1) a++;
		if (x>=1) b++;
		if(y<=-1)c++;
		if(x<=-1) d++;
	}
	int maxx=max(a,max(b,max(c,d)));
	if(maxx==a) {
		cout<<maxx<<"\n";
		cout<<sx+0<<" "<<sy+1<<"\n";
	}
	else if(maxx==b) {
		cout<<maxx<<"\n";
		cout<<sx+1<<" "<<sy+0<<"\n";
	}
	else if(maxx==c) {
		cout<<maxx<<"\n";
		cout<<sx+0<<" "<<sy-1<<"\n";
	}
	else if(maxx==d) {
		cout<<maxx<<"\n";
		cout<<sx-1<<" "<<sy+0<<"\n";
	}
return 0;
}
