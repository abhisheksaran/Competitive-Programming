

#include<bits/stdc++.h>
using namespace std;

int main(){
        long a=2000000000;
        //for(long x=100000000;x<=a;x=x+100000000){

        for(int i=1;i<=212;i++){
                for(int j=i+1;j<=2000;j++){
                        for(int  k=j+1;k<=2000;k++){
                                
				int d=(i+j+k)/(i*j*k-1);
				cout<<d;
                                if((d*i*j*k==d+i+j+k)&&d>=k) {
                                        cout<<(double)(i/100)<<" "<<(double)(j/100)<<" "<<(double)(k/100)<<" "<<double(d/100)<<"\n";
                                }
                        }
                }
        }
       // }
        return 0;
}

