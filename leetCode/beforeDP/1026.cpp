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
    
    // just keep track of mix and min ele on each path from root till leaf
    int helper(TreeNode* root, int mx, int mn ){
        //go till the leaf and return mx-mn which is the highest abosulte difference on the path from root to this leaf
        if(!root) return mx-mn;
        //find the max of both branches and return it
        return max(helper(root->left,max(mx,root->val),min(mn,root->val)),helper(root->right,max(mx,root->val),min(mn,root->val)));
        
    }
    int maxAncestorDiff(TreeNode* root) {
        if(!root) return 0;
        return helper(root, root->val, root->val);
    }
};
