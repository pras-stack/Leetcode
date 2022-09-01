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
class Solution {
public:
    int cc = 0;  
    void dfs(TreeNode* root, int maxSoFar) {   //maintain maxsofar : path's max value 
        
        if(root) {
            if(root->val >= maxSoFar) cc++;      //        maintain counter cc : if path satisfies our constraints : cc+=1
            
            dfs(root->left, max(maxSoFar,root->val));
            dfs(root->right, max(maxSoFar,root->val));
        }
    }
    int goodNodes(TreeNode* root) {
        dfs(root, INT_MIN);
        return cc;
    }
};