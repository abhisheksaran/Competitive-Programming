class Solution {
public:
    bool canThreePartsEqualSum(vector<int>& A) {
        int s=0;
        for(int i=0;i<A.size();i++) s+=A[i];
        if(s%3!=0) return false ;
        s=s/3;
        
        int s2=0;
        int part=0;
        //stop when you find 3 part even if we haven;t reached to the end, we are sure that sum of the rest of the ele would be zero and they can be appended to the last part
        for(int i=0;i<A.size()&&part<3;i++){
            s2+=A[i];
            if(s2==s){
                part++;
                s2=0;
            }
        }
        if(part==3) return true;
        else return false;
        
    }
};
