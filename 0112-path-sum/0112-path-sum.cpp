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
void helper(TreeNode* root , int target , bool& flag , int s){
    if(root == NULL)return;

    s = s+ root->val;

    if(!root->left && !root->right){
        if(s== target){
            flag = true;
        }
        return;
    }
    helper(root->left , target , flag , s);
    helper(root->right , target , flag , s);


}
    bool hasPathSum(TreeNode* root, int targetSum) {
        if(root == NULL)return false;
        int s=0;
        bool flag = false;

        helper( root , targetSum , flag , s);

        return flag;
    }
};