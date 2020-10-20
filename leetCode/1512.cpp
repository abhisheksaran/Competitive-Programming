//1:33
class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        int ans=0;
        unordered_map<int,int> f;
        for(int i=0;i<nums.size();i++){
            if(f.find(nums[i])==f.end()) f[nums[i]]=1;
            else{
                ans+=f[nums[i]];
                f[nums[i]]++;
            }
            cout<<ans<<endl;
        }
        return ans;
    }
};
//1:41
