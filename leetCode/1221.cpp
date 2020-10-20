//2:23
class Solution {
public:
	// keep counting the number of Rs and Ls. whenever they are equal, that would be one of the answer split
    int balancedStringSplit(string s) {
        int cnt=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            //cnt += s[i] == 'L' ? 1 : -1; or
            (s[i]=='L') ? cnt++:cnt-- ;
            if(cnt==0) ans++;       
        }
        return ans;
        
    }
};
//2:29
