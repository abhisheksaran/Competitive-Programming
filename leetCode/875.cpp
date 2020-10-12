//23:04
//same kind of concept, binary on ans;
class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int H) {
        int left=1;
        int right=piles[0];
        for(int i=0;i<piles.size();i++) right=max(right, piles[i]);
        
        while(left<right){
            
            int m=left+(right-left)/2;
            int hoursNeeded=0;
            for(int i=0;i<piles.size();i++){
                hoursNeeded+=(ceil((piles[i])/(float)m));
            }
            if(hoursNeeded>H) left=m+1;
            else right=m;
        }
        return right;
        
    }
};
//23:21
