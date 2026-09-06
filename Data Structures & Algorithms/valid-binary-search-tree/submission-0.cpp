
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
    bool isVal(TreeNode* root, long long mini, long long maxi){
        if(!root) return true;
        if(root->val>=maxi||root->val<=mini){
            return false;
        }

        return isVal(root->left, mini, root->val) && isVal(root->right, root->val, maxi);
    }

    bool isValidBST(TreeNode* root) {
        return isVal(root, LONG_MIN, LONG_MAX);
    }
};
