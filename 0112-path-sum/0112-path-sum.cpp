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
bool  flag = false;
bool helper(TreeNode* root , int target , int sum){
    if(root== NULL) return flag;

    sum = sum+ root->val;

    if(root->left == NULL && root->right == NULL){
        if(sum == target){
            flag = true;
            return flag;
        }
    }
    helper(root->left , target , sum);
    helper(root->right , target , sum);

    return flag;

}
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL && targetSum == NULL){
            return false;
        }
    
        return helper(root , targetSum , 0);
       
    }
};