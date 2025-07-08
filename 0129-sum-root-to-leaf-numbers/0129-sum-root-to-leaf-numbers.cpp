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
void helper(TreeNode* root , int & ans , int x){
    if(root == NULL){
        return;
    }

    x= x*10 + root->val;

    if(root->left == NULL && root->right == NULL){
        ans = ans+x;
        return;
    }    

    helper(root->left , ans , x);
    helper(root->right , ans , x);
}
    int sumNumbers(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int ans =0;
        helper(root , ans , 0);

        return ans;
        
    }
};