//10:51
//seems a good question, i wasn;t able to grab the question very well
//the concept of seen hashmap is very cool
//again think about the general probelem where we have to find the maximum length subarray for which sum>=k
//this problem is specificcally asking us to solve the problem to find the maximum length subarray in prefix sum for which sum is >=1

class Solution {
public:
    int longestWPI(vector<int>& hours) {
        //prefix sum 
        vector<int> ps(hours.size(),0);
        if(hours[0]>8) ps[0]=1;
        else ps[0]=-1;
        for(int i=1;i<hours.size();i++){
            if(hours[i]>8) ps[i]=1+ps[i-1];
            else ps[i]=-1+ps[i-1];
           
        }
        
        int res=0;
        unordered_map<int,int> seen;
        seen[ps[0]]=0;
        for(int i=0;i<hours.size();i++){
            if(ps[i]>0) res=max(res,i+1);
            else{
                if(seen.find(ps[i])==seen.end()){
                    seen[ps[i]]=i;
                }
                if(seen.find(ps[i]-1)!=seen.end()){
                    res=max(res,i-seen[ps[i]-1]);
                }
            }
            
            
        }
        return res;
        
    }
};
//12:00

