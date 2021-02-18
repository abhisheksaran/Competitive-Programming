class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        
        int m = matrix.size();
        int n = matrix[0].size();
        
        //dp[i][j] is the maxm dimension of the all one square in the range (0,0) to (i,j) ie Left up sqaure at (i,j)) 
        vector<vector<int>> dp(m, vector<int> (n,0));
        dp[0][0] = matrix[0][0] - '0';
        
        int mx = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(matrix[i][j] == '0') dp[i][j] = 0;
                else{
                    //base case
                    dp[i][j] = 1;
                    if(i>0 && j>0){
                        //take min of left, up and left up, 
                        dp[i][j] = max(min(dp[i-1][j-1],min(dp[i-1][j], dp[i][j-1]))+1, dp[i][j] ); 
                    }
                }
                mx = max(mx, dp[i][j]);
            }
            
        }
        return mx*mx;
    }
};
/*
 * Hint 1: How will you know the size of square ending at (i,j) if you know the size of square at (i-1,j), (i,j-1) and (i-1,j-1).
 * Space complexity can be optimised to O(rowSize)
 */
