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
bool helper(TreeNode* root , int target ,int curr){
    if(root == NULL){
        return false;
    }
    curr = curr + root->val;

    if(root->left == NULL && root->right == NULL){
        if(curr == target){
            return true;
        }
    }
    return helper(root->left, target,curr) || helper(root->right ,target,curr);

}

    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL || targetSum == 0){
            return false;
        }
        int curr =0;
        return helper(root , targetSum , curr);
    }
};

