//12:22
class Solution {
public:
    int trap(vector<int>& height) {
        //find the index of max ele in left till i
        //find the index of max ele in right from i to end
        
        int n=height.size();
        if(n==0) return 0;
        vector<int> ngl(n,-1);
        vector<int> ngr(n,-1);
        ngl[0]=0;
        for(int i=1;i<n;i++){
            if(height[i]<height[ngl[i-1]]) ngl[i]=ngl[i-1];
            else ngl[i]=i;
        }
        ngr[n-1]=n-1;
        for(int i=n-2;i>=0;i--){
            if(height[i]<height[ngr[i+1]]) ngr[i]=ngr[i+1];
            else ngr[i]=i;
        }
       
        
        //ans will be sum((min(height(ngr[i]),height(ngl[i])))-height[i]) for all i's
        int ans=0;
        for(int i=0;i<n;i++){
            ans+=(min(height[ngr[i]],height[ngl[i]])-height[i]);
            
            cout<<i<<" "<<ans<<"\n";
        }
        return ans;
    }
};
//13:08
