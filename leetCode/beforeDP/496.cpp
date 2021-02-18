class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        stack<int> s;
        if(nums2.size()>0) s.push(nums2[nums2.size()-1]);
        unordered_map<int,int> ngr;
        
        //looping from the end to find the next greater element to right
        //if top of stack is greater than the current ele, that would be the greater ele
        //if it isn;t than keep poping out till you get a greater ele(these elements can't be answer anymore because curr ele is greater than all popped out eles and nearest too) , that would be the greater next for curr ele 
        //and finally push the curr ele on top of stack in both of the cases 
        for(int i=nums2.size()-2;i>=0;i--){
            if(nums2[i]<s.top()){
                ngr[nums2[i]]=s.top();
                s.push(nums2[i]);
            }
            else {
                while(!s.empty()&&nums2[i]>=s.top()) s.pop();
                if(!s.empty()) ngr[nums2[i]]=s.top();
                s.push(nums2[i]);
            }
        }
        
        //to find the ngr ele, search it on map
        for(int i=0;i<nums1.size();i++){
            if(ngr.find(nums1[i])==ngr.end()) nums1[i]=-1;
            else nums1[i]=ngr[nums1[i]];
        }
        return nums1;   
    }
};
