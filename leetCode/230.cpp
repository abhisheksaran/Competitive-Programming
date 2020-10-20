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
    //good question, I have done it earlier but it seems easy now
    //just do inorder traversal and return when you get kth element
    int kthSmallest(TreeNode* root, int &k) {
        
        if(!root) return 0;
        //if the ele has been found in the left subtree, return the answer 
        int x=kthSmallest(root->left,k);
        if(k==0) return x;
        //when k become 0 and answer is found, return it 
        k--;
        if(k==0) return root->val;
        //if answer is yet not found, search it int the right subtree
        else return kthSmallest(root->right,k);

    }
};
