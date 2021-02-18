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
    //simple bfs
    vector<double> averageOfLevels(TreeNode* root) {
        vector<double> ans;
        queue<TreeNode* > q;
        q.push(root);
        while(!q.empty()){
            int size= q.size();
            double lsum=0;
            for(int i=0;i<size;i++){
                TreeNode* u=q.front();
                lsum+=u->val;
                q.pop();
                if(u->right!=NULL) q.push(u->right);
                if(u->left!=NULL) q.push(u->left);
            }
            ans.push_back(lsum/size);   
        }
        return ans;
    }
};
