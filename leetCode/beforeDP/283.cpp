class Solution {
public:
    
    
    void moveZeroes(vector<int>& nums) {
        int n=nums.size();
        int i=0;
        while(i<nums.size()){
            if(nums[i]==0) {
                nums.erase(nums.begin()+i);
                
            }
            else i++;
        }
        int zeros=n-nums.size();
        for(i=0;i<zeros;i++){
            cout<<i<<endl;
            nums.push_back(0);
        }
       
        //another good soulution is using snow ball
        //keep accumalating zeros together as we go along and increase count_zeros if ele is zero else swap the non zero with left most zero
    }
};
