/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    //store the sum in hashmap and traverse the tree using dfs
    int dfs(TreeNode* root, unordered_map<int,int> &f,int &hf){
        if(!root) return 0;
        /*
        int x=0,y=0;
        if(root->left!=NULL) x=dfs(root->left,f,hf);
        if(root->right!=NULL) y=dfs(root->right,f,hf);
        f[x+y+root->val]++;
        hf=max(hf,f[x+y+root->val]);
        */
        //all this can be written in just this one line, how beautiful
        int s=dfs(root->left,f,hf)+dfs(root->right,f,hf)+root->val;
        hf=max(hf,++f[s]);
        return s;
    }
    //find the sums corresponding to highest frequency 
    vector<int> findFrequentTreeSum(TreeNode* root) {
        unordered_map<int,int> f;
        int highestFreq=0;
        dfs(root,f,highestFreq);
        cout<<highestFreq<<endl;
        vector<int> ans;
        for(auto v: f){
            cout<<v.first<<" "<<v.second<<endl;
            if(v.second==highestFreq) ans.push_back(v.first);
        }
        return ans;
        
    }
}
