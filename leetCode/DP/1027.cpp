class Solution {
public:
    int longestArithSeqLength(vector<int>& a) {
        
        int n = a.size();
        int mn = *min_element(a.begin(),a.end());
        int mx = *max_element(a.begin(),a.end());
        
        int d = mx -mn ;
        vector<vector<int>> dp(n,vector<int>(d+1,1));
        
        //dp[i][d] stand for the length of longest airthmatic subsequence ending with a[i] and the arithmatic differnce d;
            
        int ans = 0;
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[i]>=a[j]){
                    dp[i][a[i]-a[j]] = 1 + dp[j][a[i]-a[j]];
                    ans = max(ans, dp[i][a[i]-a[j]]); 
                }
                      
            }
        }
        
        //the case when we are getting subsequence of airthmatic diff = 1
        //we can reduce this by oberving that A[i]<=500 only so that the difference would be maximum 500 only 
        //Thus we can incorporate the case by doing d = a[i]-a[j] + 501 ;
        reverse(a.begin(),a.end());
        dp.assign(n,vector<int>(d+1,1));
        for(int i=1;i<n;i++){
            for(int j=0;j<i;j++){
                if(a[i]>=a[j]){
                    dp[i][a[i]-a[j]] = 1 + dp[j][a[i]-a[j]];
                    ans = max(ans, dp[i][a[i]-a[j]]); 
                }
                      
            }
        }
        
        return ans;
    }
};

