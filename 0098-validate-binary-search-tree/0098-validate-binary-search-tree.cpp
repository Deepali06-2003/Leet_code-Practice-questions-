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


int max_ele(TreeNode* root , int max_el){
    if(root == NULL)return max_el;
    max_el = max(max_el , root->val);
    return max_ele(root->right , max_el);
}
int min_ele(TreeNode* root, int min_el){
    if(root == NULL)return min_el;

    min_el = min(min_el , root->val);
    return min_ele(root->left , min_el);
}
    bool isValidBST(TreeNode* root) {
        if(root == NULL || (root->left == NULL && root->right == NULL))return true;

        if(root->left){
            int rl = max_ele(root->left, INT_MIN);
            if(rl >= root->val)return false;
        }
        if(root->right){
            int rr = min_ele(root->right, INT_MAX);
            if(rr <= root->val)return false;
        }

        return isValidBST(root->left) && isValidBST(root->right);
    }
};