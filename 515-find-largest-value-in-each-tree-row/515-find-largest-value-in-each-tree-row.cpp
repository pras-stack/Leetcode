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
    vector<int>ans;
    vector<int> largestValues(TreeNode* root)
    {
        traversal(root,0);
        return ans;
    }
    
    void traversal(TreeNode* root, int level)
    {
        if(!root)
        return;
        if(level<ans.size())
        {
            if(root->val > ans[level])
            ans[level] = root->val;
        }
        else
        {
            ans.push_back(root->val);
        }
        
        traversal(root->left,level+1);
        traversal(root->right,level+1);
    }
};

/*vector<int>ans;
    
    vector<int> largestValues(Node* root)
    {
        traversal(root,0);
        return ans;
    }
    
    void traversal(Node* root, int level)
    {
        if(!root)
        return;
        if(level<ans.size())
        {
            if(root->data>ans[level])
            ans[level]=root->data;
        }
        else
        {
            ans.push_back(root->data);
        }
        
        traversal(root->left,level+1);
        traversal(root->right,level+1);
    }
};*/