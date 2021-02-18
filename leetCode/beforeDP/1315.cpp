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
    int sumEvenGrandparent(TreeNode* root) {
        //another level order traversal
        queue<TreeNode* > q;
        q.push(root);
        int sum=0;
        while(!q.empty()){
            int size=q.size();
            for(int i=0;i<size;i++){
                TreeNode* u=q.front();
                q.pop();
                if(u->left!=NULL ) q.push(u->left);
                if(u->right!=NULL) q.push(u->right);
                if(u->val %2==0){
                    if(u->left!=NULL&&u->left->left!=NULL) sum=sum+u->left->left->val;
                    if(u->left!=NULL&&u->left->right!=NULL) sum=sum+u->left->right->val;
                    if(u->right!=NULL&&u->right->left!=NULL) sum=sum+u->right->left->val;
                    if(u->right!=NULL&&u->right->right!=NULL) sum=sum+u->right->right->val;
                }

            }
        }
        return sum;
        
    }
};
