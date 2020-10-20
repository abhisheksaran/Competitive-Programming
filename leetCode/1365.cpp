//1:48
class Solution {
public:
    vector<int> smallerNumbersThanCurrent(vector<int>& nums) {
        vector<int> temp=nums;
        sort(temp.begin(),temp.end());
        //idx stores the position where the element appears in the sorted list for first time and which is the same as count of smaller numbers in the array for the curr ele
        unordered_map<int,int> idx;
        for(int i=0;i<temp.size();i++){
            if(idx.find(temp[i])==idx.end()) idx[temp[i]]=i;
        }
        //cout<<temp.size()<<endl;
        for(int i=0;i<nums.size();i++) nums[i]=idx[nums[i]];
        return nums;
        
        
//another approach 
        // as nums[i]<=100 
        // take as 101 size array to store the count of numnbers 
        // and take the running sum 
        // see discussion for more
    }
};
//2:20
