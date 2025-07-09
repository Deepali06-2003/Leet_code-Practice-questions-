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
void helper(TreeNode* root , int h){
    if(root== NULL) return;

    if(root->left != NULL || root->right != NULL){
        TreeNode* lc = root->left;
        TreeNode* rc = root->right;

        root->left = rc;
        root->right = lc;
        h++;
    }
    helper(root->left , h);
    helper(root->right , h);
}
    TreeNode* invertTree(TreeNode* root) {

        if(root == NULL){
            return root;
        }
        if(root->left == NULL && root->right == NULL){
            return root;
        }
        
       
        helper(root , 0);

        return root;
    }
};