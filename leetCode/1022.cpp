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


vector<pair<int,int>> sumUtil(TreeNode* root, int &h){
    
    vector<pair<int,int>> vpl;
    vector<pair<int,int>> vpr;
    if(root->left !=NULL) vpl=sumUtil(root->left);
    if(root->right !=NULL) vpl=sumUtil(root->right);
    
    for(int i=0;i<n;i++){
        
    }
    
}

class Solution {
public:
    int sumRootToLeaf(TreeNode* root) {
        int ans=0;
        int h=0
        sumUtil(TreeNode* root,h);
        
    }
};
