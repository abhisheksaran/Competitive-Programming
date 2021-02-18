class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        //dp[i] is length of lonegest incr subseq ending at i
        vector<int> dp(n,1);
        
        int mx = INT_MIN;
        for(int i=0;i<n;i++){
            for(int j=0;j<i;j++){
                if(nums[j]<nums[i])dp[i] = max(dp[j]+1,dp[i]);
            }
            mx = max(mx,dp[i]);
        }
        return mx;
        
        
    }
};
/*
*Hint: (For nlogn) have an array where array[i] stores the tail of minimum increasing subsequence of length i. Refer geeks for geeks to learn the smulating steps for this array
*
*/
