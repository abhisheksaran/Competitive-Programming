class Solution {
public:
    int maxDistance(vector<int>& position, int m) {
        //range of answer will be between 0 and (maxpos-minpos)
        //o(nlogn) 
        sort(position.begin(),position.end());
        int n=position.size();
        
        //bin search on ans
        int i=0;
        int j=position[n-1]-position[0];
        
        while(i<=j){
            int mid=i+(j-i)/2;
            
            //to find out if this minimum distance is possible 
            int needM=1;
            int lastIdx=0;
            for(int k=1;k<n;k++){
                if(position[k]-position[lastIdx]>=mid){
                    needM++;
                    lastIdx=k;
                }     
            }
            //yes possible than update the search space to be greater than mid and j
            if(needM>=m) i=mid+1;
            //if not possible than we need to need to lower down our search space between i and mid-1
            else j=mid-1;
        }
        //i will be the number just greater than ans when loop ends
        return i-1;
    }
};
