class Solution {
public:
    // sort the array
    // 
    int triangleNumber(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        int ans=0;
        //nums[i] is the greatest size of the triangle
        for(int i=n-1;i>=2;i--){
            // here, for each middle size of the triangle, we try to find the minimum lowest size which satisfies the traingle equality
            int l=0;
            int r=i-1;
            while(l<r){
                if(nums[l]+nums[r]>nums[i]){
                    ans=ans+(r-l);
                    r--;
                }
                else l++;
            }
            
        }
        
        
        return ans;
        
    }
};
