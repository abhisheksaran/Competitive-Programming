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
    //use a helper function which returns the height of the subtree and the common ancestor
    // if both the children are in same height, the lcs would be root
    //otherwise the one which has higher height
    pair<TreeNode*, int> helper(TreeNode* root){
        if(!root) return {NULL, 0};
        auto left= helper(root->left);
        auto right=helper(root->right);
        //if any child has height greater than other one that greater one would be the common ancestor
        if (left.second>right.second) return {left.first, left.second+1};
        else if(left.second<right.second) return {right.first,right.second+1 };
        else return {root,left.second+1};
        
        
        
    }
    
    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        return helper(root).first;
        
    }
};