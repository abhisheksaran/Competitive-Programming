class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        
        //top down dp
        int n = triangle.size();
        
        //dp_curr[i][j] is the minimum sum from starting to triangle[currRow][j];
        vector<int> dp_curr(n,INT_MAX);
        //the mimum sum till last row  
        vector<int> dp_last(n,INT_MAX);
        
        //base case;
        dp_last[0] = triangle [0][0];

        for(int i=1;i<n;i++)
        {
            for(int j=0;j<=i;j++){
                //take min of adjacents of last row + curr triangle element
                if(j==0) dp_curr[j] = triangle[i][j] + dp_last[j];
                else if(j==i) dp_curr[j] = triangle[i][j] + dp_last[j-1];
                else dp_curr[j] = triangle[i][j] + min(dp_last[j], dp_last[j-1]); 
            }
            swap(dp_curr,dp_last);
            
        }  
        
        //answer would be min of last row
        int mn = INT_MAX;
        for(int i =0;i<n;i++){
            mn = min(mn, dp_last[i]);
        }
        return mn;
    }
};
//bottom up would be too easy 
