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
private:
    int maxSum;

    int helper(TreeNode* node) {
        if (!node) return 0;

        int left = max(0, helper(node->left));
        int right = max(0, helper(node->right));

        int curr_sum = node->val + left + right;
        maxSum = max(maxSum, curr_sum);

        return node->val + max(left, right);
    }

public:
    int maxPathSum(TreeNode* root) {
        maxSum = INT_MIN;
        helper(root);
        return maxSum;
    }
};
