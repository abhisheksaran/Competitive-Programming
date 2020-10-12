//20:32
class Solution {
public:
    int mySqrt(int x) {
        //return the number whose square is less than or equal to target
        // use binary search
        //we wull find upper bound and our answer will be upper bound -1
        if(x==1) return 1;
        int s=1;
        int e=x;
        while(s<=e){//in case of lower bound it would have been (s<e)
            long m=s+(e-s)/2;
            if(m*m> x) e=(int)m-1;
            else s=(int)m+1; //in case of lower bound it would have been m 
        }
        return s-1;
        
    }
};
//20:48
