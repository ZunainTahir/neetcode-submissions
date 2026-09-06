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
    int helper(TreeNode* root, int maximum){
        if(!root) return 0;

        int count=0;
        if(root->val>=maximum){
            count=1;
            maximum=root->val;
        }

        count+= helper(root->left, maximum);
        count+= helper(root->right, maximum);
        return count;
    }

    int goodNodes(TreeNode* root) {
            if(!root) return 0;
            return helper(root, root->val);
    }
};
