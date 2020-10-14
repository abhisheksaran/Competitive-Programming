class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        //the question is to find nearest greater ro right
        //take a stack and loop from the back
        //store the index in the stack and keep popping out till you didn't get the index which has greater val;
        stack<int> s;
        s.push(T.size()-1);
        vector<int> ans(T.size(),0);
        for(int i=T.size()-2;i>=0;i--){
            if(T[s.top()]>T[i]){
                ans[i]=s.top()-i;
            }
            else{
                while(!s.empty()&&T[s.top()]<=T[i]) s.pop();
                if(!s.empty()) ans[i]=s.top()-i;
            }
            s.push(i);
        }
        return ans;
    }
};
