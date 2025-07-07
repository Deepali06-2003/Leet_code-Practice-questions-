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
int checkHeight(TreeNode* root) {
        if (root == NULL) return 0;

        int leftHeight = checkHeight(root->left);
        if (leftHeight == -1) return -1;  // left subtree not balanced

        int rightHeight = checkHeight(root->right);
        if (rightHeight == -1) return -1; // right subtree not balanced

        if (abs(leftHeight - rightHeight) > 1) return -1; // current node 

        return max(leftHeight, rightHeight)+1 ;  // return height
}
    
    bool isBalanced(TreeNode* root) {
        return checkHeight(root)!= -1;
    }
};