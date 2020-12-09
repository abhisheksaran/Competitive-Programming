class Solution {
public:
    int numRollsToTarget(int d, int f, int target) {
        int m = 1e9 + 7;
        //recursion
        //ans(d,f,target) = F + ans(d-1,f,target-F),where F ranges over 1 to f
        //covert this to bottom up dp
        vector<vector<int>> dp (d+1,vector<int> (target+1,0));
        for(int j=1;j<=min(target,f);j++) dp[1][j]=1 ; 
        
        for(int i=2;i<=d;i++){
            for(int j=1;j<=target;j++){
                for(int k=1; k<=min(f,j) ;k++){
                    dp[i][j] = ((dp[i][j])%m + ((dp[i-1][j-k])%m))%m ;
                }
            }
        }
        return dp[d][target];
    }
};
//further space optimization can be done as we only need one last row.
