//13:43
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        //sorted order, can use binary search lower bound which gives us pointer to the least position to the ele whhich greater than or equal to target ele
        auto it = lower_bound( nums.begin(),nums.end(), target);
        return it-nums.begin();
    }
};
//13:50

