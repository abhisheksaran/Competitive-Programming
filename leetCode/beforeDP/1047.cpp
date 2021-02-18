class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> s;
        
        int i=0;
        int cnt;
        while(i<S.size()){
            cnt=0;
            if(s.empty()) s.push(S[i]);
            else if(s.top()==S[i]){
                    s.pop();
                    cnt=2;
                    S.erase(i+1-cnt,cnt);
            }
            else s.push(S[i]);
            i=i+1-cnt;
            
        }

       return S;
        
    }
};class Solution {
public:
    string removeDuplicates(string S) {
        stack<char> s;
        
        int i=0;
        int cnt;
        while(i<S.size()){
            cnt=0;
            if(s.empty()) s.push(S[i]);
            else if(s.top()==S[i]){
                    s.pop();
                    cnt=2;
                    S.erase(i+1-cnt,cnt);
            }
            else s.push(S[i]);
            i=i+1-cnt;
            
        }

       return S;
        
    }
};
