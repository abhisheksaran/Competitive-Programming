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
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if(t1==NULL) return t2;
        else if (t2==NULL) return t1;
        else {
            t1->val+=t2->val;
            if(t1->right==NULL) t1->right=t2->right;
            else t1->right=mergeTrees(t1->right,t2->right);
            if(t1->left==NULL) t1->left=t2->left;
            else t1->left=mergeTrees(t1->left,t2->left);
            
        }
        return t1;
    }
};
