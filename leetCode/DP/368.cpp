
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& arr) {
        int n = arr.size();
        if(n==0) return arr;

        sort(arr.begin(),arr.end());
        vector<int> dp(n,1);
        int maxCountIndex = 0;
        int maxCount = 1;
        for(int i=1 ;i<n;i++){
            for(int j= 0;j<i;j++){
                if(arr[i]%arr[j] == 0 ) dp[i] = max(dp[i],dp[j]+1);
            }
            if(dp[i]>maxCount){
                maxCount = dp[i];
                maxCountIndex  = i;
            }
        }

        //get the set
        vector<int> ans;
        int next = arr[maxCountIndex];
        for(int i = maxCountIndex; i>=0; i--){
            if(next%arr[i]==0 && dp[i] == maxCount){
                ans.push_back(arr[i]);
                maxCount --;
                next = arr[i];
            }

        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};
/*
 *Hint 1 : sort the input
 *Hint 2 : LIS kind of approach
 *Hint 3 : Find the maximum count first and then generate the set with backtracking
 * /
