class Solution {
public:
    int coinChange(vector<int>& arr, int amount) {
        //this initialization is important 
        vector<int> dp_curr(amount+1,INT_MAX-1);
        vector<int> dp_prev(amount+1,INT_MAX-1);
        int n = arr.size();
        
        //base case
        dp_prev[0] = 0;
        dp_curr[0] = 0;
        
        for(int i =0 ; i<n;i++){
            if(arr[i]<=amount) dp_prev[arr[i]] = 1;
        }
        
        for(int i =0;i<n;i++){
            for(int j =1;j<=amount;j++){
                if(arr[i] > j) dp_curr[j] = dp_prev[j] ;
                else dp_curr[j] = min(1+dp_curr[j-arr[i]], dp_prev[j]);
            }
            swap(dp_curr,dp_prev);
        }
        
        return (dp_prev[amount]==INT_MAX-1)? -1 : dp_prev[amount];
    }
};
/*
 * Hint 1: Knapsack
 * Hint 2: Unbounded Knapsack
 *
 * I Have reduced space complexity from O(amount*lenof(arr)) to O(amount)
 * Even further, we can do it with just one array
 */
