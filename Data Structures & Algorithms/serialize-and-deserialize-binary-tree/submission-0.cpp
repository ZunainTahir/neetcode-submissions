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

class Codec {
private:
    void serialize_helper(TreeNode* node, string& out) {
        if (!node) {
            out += "N,";
            return;
        }
        out += to_string(node->val) + ",";
        serialize_helper(node->left, out);
        serialize_helper(node->right, out);
    }

    TreeNode* deserialize_helper(stringstream& ss) {
        string item;
        if (!getline(ss, item, ',')) {
            return nullptr;
        }
        if (item == "N") {
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(item));
        node->left = deserialize_helper(ss);
        node->right = deserialize_helper(ss);
        return node;
    }

public:
    string serialize(TreeNode* root) {
        string res = "";
        serialize_helper(root, res);
        return res;
    }

    TreeNode* deserialize(string data) {
        stringstream ss(data);
        return deserialize_helper(ss);
    }
};
