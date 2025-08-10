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
int s=0;
void helper(TreeNode* root){
    if(root == NULL)return ;

    if(root->left && root->left->left == NULL && root->left->right == NULL){
        s = s+ root->left->val;
    } 
    helper(root->left);
    helper(root->right);
}
    int sumOfLeftLeaves(TreeNode* root) {
        if(root == NULL)return 0;

        
        helper(root);
        return s;

    }
};