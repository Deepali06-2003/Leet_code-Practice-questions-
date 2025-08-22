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
bool helper(TreeNode* root , TreeNode* r1){
    if(root == NULL && r1 == NULL)return true;
    if(root == NULL || r1 == NULL)return false;

    if(root->val != r1->val)return false;

    return helper(root->left , r1->left) && helper(root->right , r1->right);
}
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == NULL)return false;
         if(helper(root , subRoot))return true;

        return isSubtree(root->left , subRoot) || isSubtree(root->right , subRoot);
    }
};