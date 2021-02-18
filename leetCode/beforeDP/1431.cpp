//1:21
class Solution {
public:
    vector<bool> kidsWithCandies(vector<int>& candies, int extraCandies) {
        int m=*max_element(candies.begin(),candies.end());
        vector<bool> ans(candies.size(),false);
        for(int i=0;i<candies.size();i++){
            if(candies[i]>=m-extraCandies) ans[int(i)]=true;
        }
        return ans;
    }
    
};
//1:30
