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
    bool isBalanced(TreeNode* root) {
        // Call the dfsHeight function and check if the result is not -1.
        // If it's not -1, the tree is height-balanced; otherwise, it's not.
        return dfsHeight(root) != -1;
    }

    int dfsHeight(TreeNode* root) {
        // Base case: If the current node is NULL, return 0 (height of an empty subtree).
        if (root == NULL) {
            return 0;
        }
        
        // Recursively calculate the height of the left subtree.
        int leftHeight = dfsHeight(root->left);

        // If the left subtree is not height-balanced, return -1.
        if (leftHeight == -1) {
            return -1;
        }
        
        // Recursively calculate the height of the right subtree.
        int rightHeight = dfsHeight(root->right);

        // If the right subtree is not height-balanced, return -1.
        if (rightHeight == -1) {
            return -1;
        }
        
        // Check if the absolute difference between the heights of the left and right subtrees
        // is greater than 1. If yes, the current subtree is not height-balanced, so return -1.
        if (abs(leftHeight - rightHeight) > 1) {
            return -1;
        }

        // Return the maximum height between the left and right subtrees, plus 1 (for the current node).
        return max(leftHeight, rightHeight) + 1;
    }
};
