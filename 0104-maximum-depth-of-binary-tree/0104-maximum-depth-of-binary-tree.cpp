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
void helper(TreeNode* root , int height , int& ans){
    if(root == NULL)
    return;
    height++;
    if(root->left == NULL && root->right== NULL){
        ans = max(ans , height);
        return;
    }

    helper(root->left , height , ans);
    helper(root->right , height , ans);
   
}
    int maxDepth(TreeNode* root) {
        if(root == NULL){
            return 0;
        }
        int ans=0;
        helper(root, 0 , ans);

        return ans;

    }
};