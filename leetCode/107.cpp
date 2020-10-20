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
    //again bfs man
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int> > ans;
        if(root==NULL) return ans;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int size= q.size();
            vector<int> temp;
            for(int i=0;i<size;i++){
                TreeNode* u=q.front();
                q.pop();
                temp.push_back(u->val);
                if(u->left!=NULL) q.push(u->left);
                if(u->right!=NULL) q.push(u->right);
            }
            ans.push_back(temp);
            
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};
