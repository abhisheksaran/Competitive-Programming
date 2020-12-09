class Solution {
public:

    int solve(int n,vector<int> &dp){
        if(n==0) return 0;

        if(dp[n]!=-1) return dp[n];
        int temp = INT_MAX;
        for(int i=1; i*i<=n;i++ ){
            temp =min(temp,solve(n-i*i,dp)+1);
            //cout<<temp<<"\n";
        }
        dp[n] = temp;
        //cout<<n<<" "<<dp[n]<<"\n";
        return dp[n];
    
    }     
    
    int numSquares(int n) {
        vector<int> dp(n+1,-1);
        dp[1]=1;
        return solve(n,dp);
    }
};
