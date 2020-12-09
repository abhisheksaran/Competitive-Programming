class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int ans = 0;
        int n = nums.size();
        for(int i=0;i<n-2;i++){
            if(nums[i]==0) continue;
            int j = i+1;
            int k = i+2;
            //3 conditions
            //nums[j]+nums[k]>nums[i] : already satisfied as k>j>i
            //nums[k]+nums[i]>nums[j] : already satisfied as k>j
            //nums[j]+nums[i]>nums[k] : we have to check and take only those pairs (j,k) which satisfies this condition
            //use two pointer

            while(j<n&&k<n){
                if(nums[k]-nums[j]>=nums[i]){
                    j++;
                }
                else{
                    ans += (k-j);
                    k++;
                }
            }
        }   
        return ans;
    }
};
