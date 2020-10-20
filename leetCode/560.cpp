class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        //get the running sum
        //traverse throught running sum and search for sum[i]-k in the hashmap
        //hashmap stores the key as sum and value as count= number of times that sum appeared in running sum array
        
        vector<int> sum(nums.size(),nums[0]);
        for(int i=1;i<nums.size();i++) {
            sum[i]=sum[i-1]+nums[i];
            cout<<sum[i]<<endl;
            
        }
        
        unordered_map <int,int> cnt;
        int ans=0;
        cnt[0]=1;
        for(int i=0;i<nums.size();i++){
            if(cnt.find(sum[i]-k)!=cnt.end()) ans+=(cnt[sum[i]-k]);

            if(cnt.find(sum[i])==cnt.end()) cnt[sum[i]]=1;
            else cnt[sum[i]]++;
        }
        return ans;
        
    }
};
