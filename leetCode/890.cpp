//1:43
class Solution {
public:
    //define two maps to address bijection between string and pattern
    //update both maps when it's not defined in both the maps
    // return true in the case if each char of string has a proper bijection 
    vector<string> findAndReplacePattern(vector<string>& words, string pattern) {
        vector<string>ans;
        for(int j=0;j<words.size();j++){
            unordered_map<char,char> um;
            unordered_map<char,char> um2;
            bool canIt=true;
            for(int i=0;i<words[j].size();i++){
                if(um.find(pattern[i])==um.end()&&um2.find(words[j][i])==um2.end()) {
                    um[pattern[i]]=words[j][i];
                    um2[words[j][i]]=pattern[i];
                }
                else if(um.find(pattern[i])!=um.end()&&um2.find(words[j][i])!=um2.end()&&um[pattern[i]]==words[j][i]&& um2[words[j][i]]==pattern[i]);
                else {
                    canIt = false;
                    break;
                }
        
            }
            if(canIt) ans.push_back(words[j]);
        }
        return ans;
    }
};
//2:13
//made a silly mistake
//seems like i should probably get some sleep
/*
again this is pure art
string F(string w) {
        unordered_map<char, int> m;
        for (char c : w) if (!m.count(c)) m[c] = m.size();
        for (int i = 0; i < w.length(); ++i) w[i] = 'a' + m[w[i]];
        return w;
    }
*/

