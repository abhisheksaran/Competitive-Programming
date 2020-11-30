
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n+1,1);
        
        for(int i=2;i<=n;i++){
            //base case
            if(i!=n) dp[i] = i;
            for(int j=1;j<=i/2;j++){
                dp[i] = max(dp[i], dp[j]*dp[i-j]);
                //cout<<i<<" "<<dp[i]<<"\n";
            }
        }
        return dp[n];
        
    }
};
