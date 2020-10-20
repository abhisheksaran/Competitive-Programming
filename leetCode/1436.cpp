//2:33
class Solution {
public:
    string destCity(vector<vector<string>>& paths) {
        //take a maps, src 
        //find out the destination city which is not in src
        vector<string> dest;
        unordered_map <string,int> src;
        for(int i=0;i<paths.size();i++){
            src[paths[i][0]]=1;
            dest.push_back(paths[i][1]);
        }
        int i;
        for(i=0;i<dest.size();i++){
            if(src.find(dest[i])==src.end()) break;
        }
        return dest[i];
        
        //another approach
        //can use set to store the src city and see which dest city is not in that set 
        
    }
};
//2:46
