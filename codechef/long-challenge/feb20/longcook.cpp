#include<bits/stdc++.h>

using namespace std;
// use gregorian calendor throughout the all span of time 
// thus  1/1 /1 will be monday
//this calander will repeat after every 400 years
//the vector a[i] shows the day of 1st feb of ith  year where 1 meant thrusday , 2 means friday .... and 0 means wednesday
//the vector b[i] calculates number of desired months from 1st to ith year (inclusive) , we only precalulate for 1st 400 years because same pattern will repeat each 400 years
int main(){
	vector<int > a(401,-1);
	a[1]=1;
	for(int i=2;i<401;i++){
		if(i%100==1)a[i]=a[i-1]+1;
		else if (i%4==1) a[i] =a[i-1]+2;
		else a[i]=a[i-1]+1;
		a[i]=a[i]%7;
	}
	vector<int> b(401,-1);
	b[1]=0;
	for(int i=2;i<401;i++){
		if(a[i]==3) b[i]=b[i-1]+1;
		else if(a[i]==4&&(i%100==0||i%4!=0)) b[i]=b[i-1]+1;
		else b[i]=b[i-1];
	}
	b[0]=0;
/*	for(int i=1;i<=400;i++){
	cout<<i<<" "<<b[i]<<"\n";
	}
*/
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int m1,y1,m2,y2;	
		cin>>m1>>y1;
		cin>>m2>>y2;
		if(m1>2) y1++;//our only focus in on 1 st day of feb
		if(m2<2) y2--;
		int x=y1/400;// x and y helps us to find how many complete 400 years cycle is there
		int y=y2/400;
		if(x==y){ //minor details 
			if(y1%400==0) cout<< b[y2%400];
			else cout<< b[y2%400]-b[y1%400-1];
		}
		else{
			if(y1%400==0&&y2%400==0) cout<<(y-x)*b[400];
			else if(y1%400==0) cout<<(b[y2%400])+(y-x)*b[400];
			else cout<<(b[400]-b[y1%400-1])+(b[y2%400])+(y-x-1)*b[400];// why y-x-1 ?? think
		}
		cout<<"\n";
	}
	
return 0;
}
