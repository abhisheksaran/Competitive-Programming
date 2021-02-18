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
    //mxSum is max of all valid BSTs
    //sum is sum of all values of this subtree if it is a BST
    //mnVal is min value of the subtree if it is a BST
    //mxVal is max value of the subtree if it is a BST
    bool solve(TreeNode* root, int& mxSum, int& sum, int& mxVal, int& mnVal){
        //base case
        if(!root->left && !root->right){
            sum = root-> val;
            mxSum = max(mxSum, sum);
            mxVal = max(mxVal,root->val);
            mnVal = min(mnVal, root->val);
            return true;
        }  
        
       else if(!root->left){
            int sumr = 0;
            int mxValS = INT_MIN;
            int mnValS = INT_MAX;
            bool temp = solve(root->right, mxSum, sumr, mxValS, mnValS);
            if(temp && root->val < mnValS){
                sum = sumr + root->val;
                mxSum = max(mxSum,sum);
                mxVal = max(mxValS,root->val);
                mnVal = min(mnValS, root->val);
                return true;
            }
            else return false;
            
        }
        else if(!root->right){
            int suml = 0;
            int mxValS = INT_MIN;
            int mnValS = INT_MAX;
            bool temp = solve(root->left, mxSum, suml, mxValS, mnValS);
            if(temp && root->val > mxValS){
                sum = suml + root->val;
                mxSum = max(mxSum,sum);
                mxVal = max(mxValS,root->val);
                mnVal = min(mnValS, root->val);
                return true;
            } 
            else return false;
        }
        else{
            int suml = 0;
            int sumr = 0;
            int mxValSL = INT_MIN;
            int mnValSL = INT_MAX;
            int mxValSR = INT_MIN;
            int mnValSR = INT_MAX;
            bool temp1 = solve(root->left, mxSum, suml, mxValSL, mnValSL);
            bool temp2 = solve(root->right, mxSum, sumr, mxValSR, mnValSR);
            if(temp1 && temp2 && root->val > mxValSL && root->val < mnValSR){
                sum = suml + sumr + root->val;
                mxSum = max(mxSum, sum);
                mxVal = max(mxValSR,root->val);
                mnVal = min(mnValSL, root->val);
                return true;
            }

            else return false;
            
        }
        
        
    }
    int maxSumBST(TreeNode* root) {
        int ans= INT_MIN;
        int sum = 0;
        int mx = INT_MIN;
        int mn = INT_MAX;

        solve(root, ans, sum, mx, mn);
        return max(ans, 0);
        
    }
};

/*
 * Suggestion:
 * try returning tuple of mxSum, mxVal, mnVal rather than passing it as parameteres
 * that would make it look more crisp ans concise
 * Catch:
 * if you try doing this with post order traversal, you might fail some test cases like- 
 * [1, null, 10, -5, 20] your output might be 26 but the actual output is 25 only.
 */

