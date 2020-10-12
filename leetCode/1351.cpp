//timestamp: 7/10 13:23
class Solution {
public:
    int countNegatives(vector<vector<int>>& grid) {
        int row= grid.size();
        int clm=grid[0].size();
        //binary serach in each row;
        int ans=0;
        for(int i=0;i<row;i++){
            auto it=lower_bound(grid[i].rbegin(), grid[i].rend(), 0);
            auto itb=grid[i].rbegin();
            ans=ans+(it-itb);
        }
        return ans;
    }
};
//timestamp: 7/10 13:33
