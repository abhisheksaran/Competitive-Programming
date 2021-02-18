//20:51
//spend some time to understand the question first

//how to figure out the binary search patterm
//observe that any capacity lower than minm capacity won't be able to ship all the packets in D days
// and similarly any capacity greater than or equal to minm capcity will be able to ship all the packets in D days
// In other words, for capacity sequence of one to sum(weights[i]), it will not be possible to deliver the packets in D days before minimum capacity value and possible for all values greater than equal to minm capacity 
// thus what we need is function isPossible(C,D) which tells us that whether with capacity C we will be able to deliver given packets in D days or not 
//and we have to binary search in the loop from 1 to sum(weights[i]) to find out the first C for which isPossible(C,D) is true;
//ready to code
        
class Solution {
public:
    
    bool isPossible(int c, int d, vector<int>& weights){
        int i=0;
        while(i<weights.size()&d>0){
            int sum=0;
            while(sum<=c&&i<weights.size()){
                sum=sum+weights[i];
                if(sum>c) break;
                i++;
            }
           d--;   
        }
        if(i==weights.size()) return true;
        else return false;
               
        
    }
    
    int shipWithinDays(vector<int>& weights, int D) {
        int s=weights[0];
        int e=0;
        for(int i=0;i<weights.size();i++){
            e+=weights[i];
            s=max(s,weights[i]);
        } 
        
        while(s<e){
            int m = s+(e-s)/2;
            if(isPossible(m,D,weights)) e=m;
            else s=m+1;
        }
        return e;
            
        
        
        
        
    }
};
//took me 45 minutes 
