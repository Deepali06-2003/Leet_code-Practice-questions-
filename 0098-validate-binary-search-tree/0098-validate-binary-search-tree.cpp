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
int min_right(int m , TreeNode* root){
    if(root == NULL) return m;
    m = min(m , root->val);
    return min_right(m , root->left);
}
int max_left(TreeNode* root , int m){
     if(root == NULL) return m;
     m = max(m , root->val);
     return max_left(root->right , m);
}
    bool isValidBST(TreeNode* root) {
        if(root == NULL){
            return true;
        }
        if(root->left){
            int lc = max_left(root->left , INT_MIN);
            if(lc >= root->val) return false;
        }

        if(root->right){
            int rc = min_right(INT_MAX , root->right);
            if(rc <= root->val) return false;
        }

        return isValidBST(root->left) and isValidBST(root->right);
    }
};