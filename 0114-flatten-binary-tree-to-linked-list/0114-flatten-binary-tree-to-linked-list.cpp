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
    void helper(TreeNode* root){
        if(root == NULL) return;

        helper(root->left);
        helper(root->right);

        TreeNode* root_l = root->left;
        TreeNode* root_r = root->right;

        root->left = NULL;
        root->right = root_l;

        TreeNode* temp = root;
        while(temp->right){
            temp = temp->right;
        }
        temp->right = root_r;
    }
    void flatten(TreeNode* root) {
        if(root== NULL)return;
        helper(root);
    }
};