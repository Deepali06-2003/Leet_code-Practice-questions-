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
void helper(TreeNode* root, int target , int s , bool& b){
    if(root == NULL)return;
    s= s+ root->val;

    if(!root->left && !root->right){
        if(s == target){
            b = true;
            return;
        }
    }
    helper(root->left , target , s, b);
    helper(root->right , target , s , b);

}
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)return false;

        int s=0;
        bool b = false;
        helper(root , targetSum, s , b);

        return b;

        
    }
};