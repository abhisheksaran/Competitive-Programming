#include<bits/stdc++.h>
using namespace std;

int main(){
  int t,a,c,b;
  cin>>t;

  for(int i=0;i<t;i++){
    cin>>a>>b>>c;
    bool sln =false;
    for(int x=-22;x<=22;x++){
      for(int y=-100;y<=100;y++){
        for(int z=-100;z<=100;z++){
          if(x+y+z==a&&(x*y*z==b)&&(x*x+y*y+z*z==c)&&x!=y&&y!=z&&x!=z)
          {
            if(x<=y)cout<<x<<" "<<y<<" "<<z<<"\n";
            else if(x>=y) cout<<y<<" "<<x<<" "<<z<<"\n";
            sln=true;
            break;
          }
        }
        if(sln) break;
      }
      if(sln) break;
    }
    if(!sln) cout<<"No solution.\n";
  }

  return 0;

}
