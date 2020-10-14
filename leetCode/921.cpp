//Minimum Add to Make Parentheses Valid
class Solution {
public:
    int minAddToMakeValid(string S) {
        stack<char> s;
        int ans=0;
        int cnt=0;
        for(int i=0;i<S.size();i++){
            
            if(S[i]=='(') s.push(S[i]);
        
            else if(!s.empty()&&s.top()=='(') s.pop();
            else{
                cnt++;
            }
        }
        ans=s.size()+cnt;
        //cout<<s.size()<<" "<<ans<<" \n";
        return ans;
        
    }
};
