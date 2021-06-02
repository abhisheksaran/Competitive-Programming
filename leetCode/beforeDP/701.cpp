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
    //insert to leaf always
    //travese to the the leaf where it sould be inserted
    //while traversing keep builiding the tree again
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if(root==NULL) root=new TreeNode(val);
        else if(val<root->val) root->left=insertIntoBST(root->left,val);
        else root->right=insertIntoBST(root->right,val);
        
        return root;
    }
};