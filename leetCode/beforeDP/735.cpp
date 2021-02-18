//23:15
//code may look bigger but look at logic it's very simple
//how you simulate the stack 
class Solution {
public:
    vector<int> asteroidCollision(vector<int>& as) {
        stack<int> s;
        int n=as.size();
        for(int i=0;i<n;i++){
            if(s.empty()) s.push(as[i]);
            else if((s.top()<0&&as[i]<0) ||(s.top()>0&&as[i]>0)||(s.top()<0&&as[i]>0)){
                s.push(as[i]);
            }
            else{
                int temp=0;
                while(!s.empty()&&(s.top()>0&&as[i]<0)) {
                    if(abs(s.top())==abs(as[i])){ 
                        s.pop();
                        temp=1;
                        break;
                    }
                    else if (abs(s.top())<abs(as[i])) {
                        s.pop();
                    }
                    else{
                        temp=1;
                        break;
                    }
                }
                if(!temp) s.push(as[i]);
                
            }
            
        }
        vector<int> ans;
        while(!s.empty()){
            ans.push_back(s.top());
            s.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
        
    }
};
//23:51
//silly problems a lot, read about question very well
