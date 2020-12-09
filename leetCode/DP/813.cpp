class Solution {
public:
    
    //double avg()
    double solve(vector<vector<double>>& dp, vector<int> &a, int i ,int k){
        //base case 
        if(k==1) return dp[i][k] = (accumulate(a.begin(),a.begin()+i,0.0)/i);
        if(dp[i][k]>=0) return dp[i][k]; 
        //at most k groups, if number of groups are more than number of elements we can decrease k
        if(i<k) return dp[i][k] = solve(dp,a,i,k-1);
        
        for(int j=1;j<i;j++){
            //dp [i][k] stores largest sum of arr(0,k) partioning in at most k groups 
            double temp = (solve(dp,a,j,k-1) + ((accumulate(a.begin()+j,a.begin()+i,0.0))/(i-j)));
            dp[i][k] = max(temp,dp[i][k]);
        }
        dp[i][k] = max(dp[i][k], dp[i][k-1]);
        return dp[i][k];
        
    }
    
    double largestSumOfAverages(vector<int>& A, int K) {
        int n = A.size();
        vector<vector<double> > dp(n+1,vector<double>(K+1,-1));
        double ans = solve(dp,A,n,K);
        /*
        for(int i=0;i<=n;i++){
            for(int j=0;j<=K;j++){
                cout<<i<<" "<<j<<" "<<dp[i][j]<<"\n";
            }
        }
        */
        return ans;
    }
};
