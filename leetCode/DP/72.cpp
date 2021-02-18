class Solution {
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        
        //lcs kind of dp
        //dp[i][j] is the min #operations to convert word1.substr(0,i) into word2.substr(0,j)
        vector<vector<int>> dp(n+1,vector<int>(m+1,INT_MAX));
        
        //base case
        dp[0][0] = 0;
        //if the other word is empty, the minm operation is either to delete all in this string or insert all in other string
        for(int i=1;i<=m;i++) dp[0][i] = i;
        for(int i=1;i<=n;i++) dp[i][0] = i;
        
        
        for(int i=1;i<=n;i++){
            for(int j=1; j<=m; j++){
                if(word1[i-1] == word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else {
                    //three choices
                    dp[i][j] = min(1+dp[i-1][j-1],min(1+dp[i-1][j], 1+dp[i][j-1]));
                }
            }
        }
        return dp[n][m];
        
    }
};
