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
bool helper(TreeNode* x , TreeNode* y){
    if(x== NULL && y == NULL)return true;
    if(x== NULL || y== NULL)return false;

    if(x->val != y->val)return false;

    return helper(x->left , y->right) && helper(x->right , y->left);
}

    bool isSymmetric(TreeNode* root) {
        if(root== NULL)return true;
       

        return helper(root->left, root->right);
        
        
    }
};