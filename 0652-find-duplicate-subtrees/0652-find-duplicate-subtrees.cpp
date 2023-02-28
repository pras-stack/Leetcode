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
    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
            vector<TreeNode*> res;
    unordered_map<string, int> m;
    preorder(root, m, res);
    return res;
}

string preorder(TreeNode* node, unordered_map<string, int>& m, vector<TreeNode*>& res) {
    if (!node) return "";
    string str = to_string(node->val) + "," + preorder(node->left, m, res) + "," + preorder(node->right, m, res);
    if (m[str] == 1) res.push_back(node);
    ++m[str];
    return str;
    }
};