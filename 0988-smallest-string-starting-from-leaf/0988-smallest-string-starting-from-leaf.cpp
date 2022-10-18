/**
 *Definition for a binary tree node.
 *struct TreeNode {
 *    int val;
 *    TreeNode * left;
 *    TreeNode * right;
 *    TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 *};
 */
class Solution
{
    public:
        string smallestFromLeaf(TreeNode *root)
        {
            string res = "~";
            helper(root, "", res);
            return res;
        }
    void helper(TreeNode *node, string cur, string &res)
    {
        if (!node) return;
        cur = string(1, node->val + 'a') + cur;
        if (!node->left && !node->right)
        {
            res = min(res, cur);
        }
        helper(node->left, cur, res);
        helper(node->right, cur, res);
    }
};