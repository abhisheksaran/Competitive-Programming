class Solution {
public:
    bool solve(string s, unordered_map < string , bool>&  dp){
        
        //dp memoization
        if(dp.find(s)!=dp.end()) return dp[s];
        
        //base case
        if(s.size()==1) return dp[s] = false;
        
        
        for(int i=1;i<s.size();i++){
            //partition the string and check if it cane be made of words in dictionary
            if(solve(s.substr(0,i), dp)){
                if(solve(s.substr(i,s.size()-i), dp)){
                    dp[s] = true;
                    break;
                }
            }    
        }
        dp[s] = false or dp[s];
        return dp[s];
        
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map < string , bool>  dp;
        int n = wordDict.size();
        
        for(int i=0 ;i < n;i ++){
            //base case 
            dp[wordDict[i]] = true;
        }
        
        return solve(s, dp);
    }
};
/*
*Hint(Iterative DP): linear dp vector, dp[i] is true if substring(0,i) can be paritioned or not 
*Hint 2: 
for(int i=1; i <= s.length(); i++){
    for(int j=0; j < i; j++){
        if(f[j] && dict.contains(s.substring(j, i))){
            f[i] = true;
            break;
        }
    }
}
*
*/
