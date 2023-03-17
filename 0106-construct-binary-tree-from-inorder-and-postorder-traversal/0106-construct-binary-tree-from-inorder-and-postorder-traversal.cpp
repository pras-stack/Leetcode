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
    int index;
    unordered_map<int,int>m;
    TreeNode* helper(vector<int>& in, vector<int>& post, int lb, int ub)
    {
        if(lb>ub) return NULL;
        
        TreeNode* root = new TreeNode(post[index]);
        index--;
        
        if(lb==ub) return root;
        
        int mid = m[root->val];
        
        
        root->right = helper(in, post, mid+1, ub);
        root->left = helper(in, post, lb, mid-1);
        
        return root;
    }
    
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) 
    {
        index = postorder.size()-1;
        for(int i=0;i<inorder.size();i++)
        {
            m[inorder[i]]=i;
        }
        TreeNode* root = helper(inorder, postorder, 0, inorder.size()-1);
        return root;
    }
};