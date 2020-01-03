#include<bits/stdc++.h>
using namespace std;

void prnt(vector<int> a,int k){
	cout<<"? ";
	for(int i=1;i<k+1;i++){
		cout<<a[i]<<" ";
	}

	cout<<"\n";
	cout.flush();
}
	
int main(){

int n,k;
cin>>n>>k;
vector<int> set1;
vector<int> set2;
int greater=-1;//which set contains index of greater values;
vector<int> comb(k+1,0);
int x=n-k;
int last_pos=-1;
int last_set=1;
int last_value=-1;
for(int i=1;i<=k;i++){
comb[i]=i;}
int l=k;
int r=n;
int replace_pos=k;
int idx=comb[replace_pos];
while(replace_pos>=1){
	for(int j=l;j<=r;j++){
		prnt(comb,k);
		int pos,val;
		cin>>pos>>val;
		if(last_pos==pos) {
			if(last_set==1) set1.push_back(idx);
			else set2.push_back(idx);

		}
		else if (last_pos==-1){
			set1.push_back(idx);
			last_set=1;
			last_pos=pos;
			last_value=val;
		}
		else {
			if(last_set==1) set2.push_back(idx);
			else set1.push_back(idx);
			if(greater==-1&&val>last_value) greater=abs(1-last_set);
			else if (greater==-1) greater=last_set;
			last_set=abs(1-last_set);
			last_pos=pos;
			last_value=val;
		}
		
		if(j+1<=n) comb[replace_pos]=j+1 ; 
		else break;
		idx=comb[replace_pos];
	}
	//change reple pos 
	l--;
	r=l;

	replace_pos--;
	comb[replace_pos]++;
	idx=replace_pos;
}

if(greater==1) cout<<"! set2size="<<set2.size()<<"\n";
else cout<<"! " << set1.size()<<"\n";
for(int x=0;x<set1.size();x++) cout<<set1[x]<<" ";

return 0;
}

