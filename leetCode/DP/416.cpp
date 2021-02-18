class Solution {
public:

    bool canPartition(vector<int>& nums) {
        int sum = 0;
        int n = nums.size();
        for(int i=0;i<n;i++){
            sum+=nums[i];
        }
        
        if(sum%2!=0) return false;
        else sum /= 2;
        
        //dp
        vector<vector<bool>> dp (n+1,vector<bool > (sum+1,false ));
        //base case 
        for(int i = 0; i<n; i++) dp[i][0] = true;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=sum;j++){
                if(nums[i-1]> j ) dp[i][j] = dp[i-1][j];
                else dp[i][j] = dp[i-1][j-nums[i-1]] || dp[i-1][j];
            }
        }
        return dp[n][sum];
    }
};

/*
*Hint 1: simple knapsack, two choices. Either include the curr ele in the set or don't
*Hint 2: can be reduced to the subset sum problems
*Hint 3: Try it solving by bitset
	Size of bitset is the maximum sum that can be achieved by array + 1.
	Ex. [5,2,4] ---> bitset of size 12 ==> 000000000001
	That means initially we can achieve sum 0 with empty array subset [ ].
	We have only 0's bit set.
*/
