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
int helper(TreeNode* root, int & ans, int curr_ans){
    if(root == NULL)return 0;

    if(root->val >= curr_ans){
        curr_ans = root->val;
        ans++;
    }

    return helper(root->left, ans, curr_ans) + helper(root->right, ans, curr_ans)+ans;
}
    int goodNodes(TreeNode* root) {
        if(root == NULL)return 0;
        int ans=0;

        helper(root, ans, INT_MIN);
        return ans;
    }
};