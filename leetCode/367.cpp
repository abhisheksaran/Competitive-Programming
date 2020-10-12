class Solution {
public:
    //take care of overflow conditions
    bool binse(int s, int e,int n){
        if(s>e) return false;
        long m= ((long)e+s)/2;
        if((m*m)==n) return true;
        else if((m*m)>n) e=(int)m-1;
        else s=(int)m+1;
        return binse(s,e,n);
    }
    //bin search from 1-num 
    bool isPerfectSquare(int num) {
        if (num==1) return true;
        else return binse(1,num,num);
         
    }
};
