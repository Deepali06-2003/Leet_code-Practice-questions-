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
TreeNode* helper(TreeNode* root){
     if(root == NULL)return NULL;

    TreeNode* lh = helper(root->left);
    TreeNode* rh = helper(root->right);

    
    TreeNode* x = root;

    root->left = NULL;
    root->right = lh;

    while(x->right){
        x= x->right;
    }
    x->right = rh;

    return root;

    

}
    void flatten(TreeNode* root) {
        if(root == NULL)return;
        helper(root);
    }
};