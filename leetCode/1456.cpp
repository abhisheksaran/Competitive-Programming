class Solution {
public:
    
    int maxVowels(string s, int k) {
        
        int mx=0;
        int v=0;
        for(int i=0;i<s.size();i++){
            if(i<k){
                if(s[i]=='a'||s[i]=='e'||s[i]=='o'||s[i]=='i'||s[i]=='u') v++;
            }    
            else {
                if(s[i]=='a'||s[i]=='e'||s[i]=='o'||s[i]=='i'||s[i]=='u') v++;
                if(s[i-k]=='a'||s[i-k]=='e'||s[i-k]=='o'||s[i-k]=='i'||s[i-k]=='u') v--;
                
            }
            mx=max(mx,v);
        }    
        return mx;
    }
};
