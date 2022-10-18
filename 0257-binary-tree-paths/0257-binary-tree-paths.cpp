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
    vector<string> ans;
    void preorder(TreeNode* root, string str){
        
        if(root == NULL){
            return;
        }
        if(root -> right == NULL and root -> left  == NULL){
            string x = to_string(root -> val);
            str.append(x);
            ans.push_back(str);
        }
        string x = to_string(root -> val);
        str.append(x);
        str.append("->");
        preorder(root-> left, str);
        preorder(root -> right, str);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string str;
        preorder(root,str);
        return ans;
    }
};