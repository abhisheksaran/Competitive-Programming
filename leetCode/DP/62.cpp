class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<int> pre(n,1);
        vector<int> cur(n,1);
        cur[0]=1;
        for(int i=1;i<m;i++){
            for(int j=1;j<n;j++){
                //number of path to current node = number of paths to left node + number of paths to above node
                cur[j] = pre[j]+cur[j-1];
                //cout<<i<<" "<<j<<" "<<cur[j]<<" "<<cur[j-1]<<" "<<pre[j]<<"\n";
            }
            swap(cur,pre);
        }
        return pre[n-1];
        
    }
};
