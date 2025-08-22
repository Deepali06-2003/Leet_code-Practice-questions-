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
int max_ele(TreeNode* root){
    if(!root) return INT_MIN;
    return max(root->val , max_ele(root->right));
}

int min_ele(TreeNode* root){
    if(!root)return INT_MAX;
    return min(root->val , min_ele(root->left));
}
    bool isValidBST(TreeNode* root) {
        if(root == NULL)return true;

        if(root->left){
            int maxL = max_ele(root->left);
            if(maxL >= root->val)return false;
        }

        if(root->right){
            int minR = min_ele(root->right);
            if(minR <= root->val)return false;
        }

        return isValidBST(root->left) && isValidBST(root->right);
    }
};