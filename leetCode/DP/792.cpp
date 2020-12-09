class Solution {
public:
    int numMatchingSubseq(string S, vector<string>& words) {
        //next[i][j] stores the index of next occurance of char j in the range [i,end]
        //this will help us in finding the if another string s2 is subsq of S or not in O(s2) rather than O(S) normally 
        vector<vector<int>> next(S.size(),vector<int>(26,-1));
        for(int i=S.size()-1;i>=0;i--) {
            //copy the next vector and then update the position of ele at ith index
            if(i<S.size()-1){
                for(int j=0;j<26;j++) next[i][j] = next[i+1][j];
            }
            next[i][S[i]-'a'] = i;
            //debug purpose
            //for(int j=0;j<26;j++) cout<<i<<" "<<j<<" "<<next[i][j]<<"\n";
        }
        
        int ans =0;
        for(int i=0;i<words.size();i++){
            int idx=-1;
            int j=0;
            for(j=0; (j<words[i].size()) && (idx < int(S.size()-1)) ; j++){
                idx = next[idx+1][words[i][j]-'a'];
                if(idx == -1) break;
            }  
            if(j==words[i].size()) ans++;
        }
        return ans;
    }
};
//Another method to knwo if s is subsq of S1 is to keep storing the indexes corresponding to each char in vector of vectors and then use binary search tto find if there exists a index for current char, index which is greater than the index for last ele. 
