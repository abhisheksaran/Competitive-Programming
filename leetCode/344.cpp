class Solution {
public:
    void reverseString(vector<char>& s) {
        int n=s.size();
        int i=0;
        while(i<(n/2)){
            char c=s[i];
            s[i]=s[n-1-i];
            s[n-1-i]=c;
            i++;
        }
        
    }
};
