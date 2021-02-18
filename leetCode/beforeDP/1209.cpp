class Solution {
public:
    //can done by stack too but we will try here this by two pointers
    string removeDuplicates(string s, int k) {
    
        string ans=s;
        int i=0;//idx in original string 
        int j=0;//idx in ans string
        //cnt to keep track of consecutive equal numbers ending with ans[j]
        vector<int> cnt(s.size(),1);
        for(int i=0;i<s.size();i++,j++){
            ans[j]=s[i];
            if(j>0&&ans[j]==ans[j-1]) cnt[j]=cnt[j-1]+1; 
            else cnt[j]=1;
            if(cnt[j]==k) j=j-k;
        }
        
        
        return ans.substr(0,j);
        
    }
    /*
    Solution 2: Stack
    Save the character c and its count to the stack.
    If the next character c is same as the last one, increment the count.
    Otherwise push a pair (c, 1) into the stack.
    I used a dummy element ('#', 0) to avoid empty stack.
    */
    
    
};
