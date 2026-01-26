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
void helper(TreeNode* root , int &ans , int c){
    if(root == NULL){
        return;
        
    }
    c++;
    if(root->left == NULL && root->right == NULL){
        ans = min(c , ans);
        return;
    }

    helper(root->left , ans , c);
    helper(root->right , ans , c);
}
    int minDepth(TreeNode* root) {
        if(root== NULL){
            return 0;
        }

        int ans =INT_MAX;
        helper(root , ans , 0);

        return ans;
        
        
    }
};