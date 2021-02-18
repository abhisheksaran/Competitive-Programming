//13:12
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        //nearesr lesser to right
        //nearesr lesser to left
        int n=heights.size();
        if(n==0) return 0;
        vector<int> nlr(n,n);
        vector<int> nll(n,-1);
        
        stack<int> s;
        for(int i=0;i<n;i++){
            if(s.empty()) s.push(i);
            else {
                while(!s.empty()&&heights[s.top()]>=heights[i]) s.pop();
                if(!s.empty()) nll[i]=s.top();
                s.push(i);
            }
        }
        
        stack<int> s2;
        for(int i=n-1;i>=0;i--){
            if(s2.empty()) s2.push(i);
            else {
                while(!s2.empty()&&heights[s2.top()]>=heights[i]) s2.pop();
                if(!s2.empty()) nlr[i]=s2.top();
                s2.push(i);
            }
        }
        
        int ans=0;
        for(int i=0;i<n;i++){
            cout<<nlr[i]<<" "<<nll[i]<<"\n";
            ans=max(ans,((nlr[i]-1)-(nll[i]+1)+1)*heights[i]);
        }
        return ans;
        
    }
};
//13:30
