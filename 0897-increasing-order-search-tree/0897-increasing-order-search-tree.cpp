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
TreeNode* curr;
void helper(TreeNode* root){
    if(root == NULL) return;

    helper(root->left);
    
    root->left = NULL;        // Remove the left child
    curr->right = root;       // Attach current node to the right
    curr = curr->right;

    helper(root->right);
}
    TreeNode* increasingBST(TreeNode* root) {
        if(root== NULL) return NULL;

        TreeNode* temp = new TreeNode(0);
        curr = temp;
        helper(root);

        return temp->right;
    }
};