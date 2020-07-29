#include<bits/stdc++.h>
using namespace std;

/*
*@author saran
*@name- Find the number of ways of  parnahtesis of given boolean expression such that expression evaluates to True.
*@type- DP
*@date- 25th July
*/

//t[i][j] will capture the number of ways this subexpression i to j, both inclusive can be evaluated to True
int t[100][100];
int f[100][100];


void solve(int s[], char op[], int i, int j){
	if(t[i][j]!=-1) return;
	
	t[i][j]=0;
	f[i][j]=0;
	for(int x=i;x<=j-1;x++){
		
		solve(s,op,i,x);
		solve(s,op,x+1,j);

//		cout<<op[x]<<" =char at "<< x<<"\n";
		 
		if(op[x]=='&'){
			t[i][j]+=(t[i][x]*t[x+1][j]);	
			f[i][j]+=(t[i][x]*f[x+1][j]+f[i][x]*t[x+1][j]+f[i][x]*f[x+1][j]);	
			
//			if(i==0&&j==2) cout<<"$ >> "<<i<<","<<j<<"= "<<t[i][j]<<" "<<f[i][j]<<"\n";
		}
		else if(op[x]=='|'){
			t[i][j]+=(t[i][x]*t[x+1][j]+t[i][x]*f[x+1][j]+f[i][x]*t[x+1][j]);	
			f[i][j]+=(f[i][x]*f[x+1][j]);	
//			if(i==0&&j==2) cout<<"| >> "<<i<<","<<j<<"= "<<t[i][j]<<" "<<f[i][j]<<"\n";
		}
			
		else if(op[x]=='^'){
		
			t[i][j]+=(t[i][x]*f[x+1][j]+f[i][x]*t[x+1][j]);	
			f[i][j]+=(t[i][x]*t[x+1][j]+f[i][x]*f[x+1][j]);	
//			if(i==0&&j==2) cout<<"^ >> "<<i<<","<<j<<"= "<<t[i][j]<<" "<<f[i][j]<<"\n";
		}
	
		

	}
	
	cout<<i<<","<<j<<"= "<<t[i][j]<<" "<<f[i][j]<<"\n";
return;
}

int main(){
	int n;
	cin>>n;
	int s[n];
	char op[n-1];
	for(int i=0;i<n;i++) cin>>s[i];
	for(int i=0;i<n-1;i++){
		cin>>op[i];
//		cout<<op[i]<<"\n";
	}
	memset(t,-1,sizeof(t));
	memset(f,-1,sizeof(f));

	for(int i=0;i<n;i++){
		if(s[i]){
			t[i][i]=1;
			f[i][i]=0;
		}
		else{
			t[i][i]=0;
			f[i][i]=1;
		
		}
	
	}
	solve(s,op,0,n-1);
	
	cout<<t[0][n-1]<<"\n";
		
	
return 0;
}
