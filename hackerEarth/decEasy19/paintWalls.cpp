    #include <bits/stdc++.h>
    using namespace std;
    int main(){
        int t;
        cin>>t;
        for(int z=0;z<t;z++){
            int n,m,k;
            cin>>n>>m>>k;
            
            vector<vector<int> > input(n,vector<int> (m,0));
            vector<vector<int> > mat_sum_h(n,vector<int> (m,0));//(i,j) stores cumalative sum of a ith row till jth column
            vector<vector<int> > mat_sum_v(m,vector<int> (n,0));//(i,j) stores cumalative sum of ith column till ith row
            for(int j=0;j<n;j++){
                int sum=0;
                for(int l=0;l<m;l++){
                    int x;
                    cin>>x;
                    input[j][l]=x;
                    sum+=x;
                    mat_sum_h[j][l]=sum;
                }
            }
            //cout<<mat_sum_h[0][1]<<"\n";
            //cout<<mat_sum_h[1][1]<<"\n";
            //horizontal painting t
            long a;
            long cost=10e9;
            for(int j=0;j<=m-k;j++){
                for(int i=0;i<n-1;i++){
                    //calculate the sum of kernal size k, j to j+k-1 which can be obtained by substracting (0 to j-1) from (0 to j+k-1 )
                    if(j>0) a=(mat_sum_h[i][j+k-1]-mat_sum_h[i][j-1])+(mat_sum_h[i+1][j+k-1]-mat_sum_h[i+1][j-1]);
                    else a=(mat_sum_h[i][j+k-1])+(mat_sum_h[i+1][j+k-1]);
                   // cout<<a<<"\n";
                    cost=min(cost,a);
                }
                
            }
            //vertical painting
            if(n>=k){//the logo should not go beyound the height of grid, to reduce extra calculation
                for(int j=0;j<m;j++){
                    int sum=0;
                    for(int l=0;l<n;l++){
                        
                        sum+=input[l][j];
                        mat_sum_v[j][l]=sum;
                    }
                }
            }
            
            for(int j=0;j<=n-k;j++){
                for(int i=0;i<m-1;i++){
                    
                    if(j>0) a=(mat_sum_v[i][j+k-1]-mat_sum_v[i][j-1])+(mat_sum_v[i+1][j+k-1]-mat_sum_v[i+1][j-1]);
                    else a=(mat_sum_v[i][j+k-1])+(mat_sum_v[i+1][j+k-1]);
                    cost=min(cost,a);
     
                }
            }
            //if(n<2||m<2) cost =-1;
            //if(n<k&&m<k) cost=-1;
            if(cost ==10e9) cost=-1;// if not possible to paint  
            cout<<cost<<"\n";
            
            
        }
    return 0;
    }
