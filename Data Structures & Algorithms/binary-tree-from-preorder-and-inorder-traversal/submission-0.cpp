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
    TreeNode* build(vector<int>& preorder, int& idx, vector<int>& inorder, int st, int end) {
        if (st > end) return nullptr;

        int value = preorder[idx++];
        TreeNode* root = new TreeNode(value);
        int split = st;
        while (inorder[split] != value) {
            split++;
        }
        root->left  = build(preorder, idx, inorder, st, split - 1);
        root->right = build(preorder, idx, inorder, split + 1, end);

        return root;
    }

public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int idx = 0;
        return build(preorder, idx, inorder, 0, inorder.size() - 1);
    }
};
