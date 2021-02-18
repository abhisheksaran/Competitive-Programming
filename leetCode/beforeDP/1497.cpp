class Solution {
public:
    //Advice: take care of negative numbers well
    bool canArrange(vector<int>& arr, int k) {
        //reaminder map
        unordered_map<int,int> r;
        int i;
        for(i=0;i<arr.size();i++){
            int remainder=arr[i]%k;
            if(remainder<0) remainder+=k;
            if(r.find(remainder)==r.end()) r[remainder]=1;
            else r[remainder]++;
        }
        if(r.find(0)!=r.end()&&r[0]%2!=0) return false;
        for(i=1;i<=k/2;i++){
            //this first condition is imp, why?
            if(k%2==0&&i==k/2&&r[i]%2!=0) return false; 
            else if(r[i]!=r[k-i]) return false;
            
        }
        return true;
        
    }
};
