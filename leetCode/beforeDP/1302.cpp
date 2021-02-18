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
    int deepestLeavesSum(TreeNode* root) {
        //same bfs, sum of last level values
        queue<TreeNode*> q;
        q.push(root);
        int sum;
        while(!q.empty()){
            int size=q.size();
            sum=0;
            for(int i=0;i<size;i++){
                TreeNode* u=q.front();
                q.pop();
                sum+=u->val;
                if(u->left!=NULL) q.push(u->left);
                if(u->right!=NULL) q.push(u->right);
            }
        }
        return sum;
        
    }
};
