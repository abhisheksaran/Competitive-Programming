#include<bits/stdc++.h>
using namespace std;

int main(){
  for(double a=.01;a<=2.20;a=a+.01){
    for(double b=a+.01;b<=2.72;b=b+.01){
      for(double c=b+.01;c<=2.72;c=c+.01){
        //if(a*b*c<=1) continue;
        double d=(a+b+c)/(a*b*c-1.00);
        double D=d*100.0;
        double Ddesh=round(D);
        double x=((d-int(d))*100);
        bool y=(x&11.11111111111111);
        //cout<<Ddesh<<" "<<D<<" "<<d<<"\n";
        //if(a==1.25&&b==1.60&&c==1.75) cout<<Ddesh<<" "<<D<<"\n";
        if(d>=c&&d<=20&&y==0){
          //cout<<Ddesh<<" "<<D<<" "<<D-Ddesh<<"\n";
           cout<<a<<" "<<b<<" "<<c<<" "<<d<<"\n";
         }
      }
    }
  }
}
