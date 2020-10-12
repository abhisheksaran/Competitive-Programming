// The API isBadVersion is defined for you.
// bool isBadVersion(int version);
//20:25
class Solution {
public:
    int firstBadVersion(int n) {
        //simple in o(n) using traversal from the start and stop when you get api call false
        //or use binary search because sorting phenomenon is there
        
        int s=1;
        int e=n;
        while(s<e){
            int m=s+(e-s)/2;
            //m=(e+s)/2 might cause integer overflow 
            if(isBadVersion(m)) e=m;
            else s=m+1;
        }
        return e;
        
    }
};
//20:28
