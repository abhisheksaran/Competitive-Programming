class Solution {
public:
    int findMaxForm(vector<string>& strs, int m, int n) {
        
        //calculate number of ones in each string 
        int s = strs.size();
        vector<int> ones(s,0);
        for(int i=0;i<s;i++){
            string str = strs[i];
            for(int j=0;j<str.size();j++){
                if(str[j]=='1') ones[i]++;
            }
        }
        
        //dp[i][j][k] indicates the largest size of subset of set of strings strs[0] to strs[i-1] such that there are at most j zeros and k ones.
        vector<vector<vector<int > > > dp(s+1, vector<vector<int>>(m+1,vector<int>(n+1,0)));
        //base case
        dp[0][0][0] = 0;
        
        int mn = INT_MIN;
        for(int k = 1 ;k<=s; k++){
            for(int i=0;i<=m;i++){
                for(int j=0;j<=n;j++){
                    if(ones[k-1]>j || strs[k-1].size()-ones[k-1]> i) dp[k][i][j] = dp[k-1][i][j];
                    else dp[k][i][j] = max( 1+dp[k-1][i-(strs[k-1].size()-ones[k-1])][j-ones[k-1]], dp[k-1][i][j]); 
                    //cout<<k<<" "<<i<<" "<<j<<" "<<dp[k][i][j]<<"\n";
                    if(k==s){
                        mn = max(mn,dp[s][i][j]);
                    }
                }
            }
        }
        return mn;
        //can reduce the space complexity as we only use the matrix of last string 
                       
    }
};
