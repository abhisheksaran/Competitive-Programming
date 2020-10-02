#include<bits/stdc++.h>
using namespace std;

int main(){
	//pre calculation
	vector<int> numOfOccrI (128,0);		// to update number of occurance of hardSeq[i] at each stage  
	vector<int> numOfOccrITillRoundI (128,0);// to store number of occurance of hardSeq[i] till i th stage 
	vector<int> lastOccrOfI(128,-1);	// last occurance of hardSeq[i]
	vector<int> hardSeq(128,-1);		//calculate hardSeq
	hardSeq[0]=0;				//initialization
	lastOccrOfI[0]=0;
	for(int i=0;i<128;i++){
		if(numOfOccrI[hardSeq[i]]==0) {//if x does not occur earlier
			hardSeq[i+1]=0;
			lastOccrOfI[hardSeq[i]]=i;
		}
		else{
			hardSeq[i+1]=i-lastOccrOfI[hardSeq[i]];
			lastOccrOfI[hardSeq[i]]=i;
		}

		//incrementing number of occurances of hardSeq [i] and then keeping record of number of occrrance of hardSeq[i] at stage i
		numOfOccrI[hardSeq[i]]++;
		numOfOccrITillRoundI[i]=numOfOccrI[hardSeq[i]];
		//cout<<hardSeq[i]<<"\n"; 	// debug purpose to see the correctness of hardSeq
	}
	
	int t;
	cin>>t;
	for(int i=0;i<t;i++){
		int n;
		cin>>n;
		n--;
		cout<<numOfOccrITillRoundI[n]<<"\n";
	}
	

return 0;
}
