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
int helper(TreeNode* root , int & ans, int curr){
    if(root == NULL)return ans;
    if(root->val >= curr){
        ans++;
        curr = root->val;
    }

    return helper(root->left , ans , curr) + helper(root->right, ans , curr)+ans;
}
    int goodNodes(TreeNode* root) {
        if(root == NULL)return 0;
        int ans =0;
         helper(root , ans , INT_MIN);
         return ans;
    }
};