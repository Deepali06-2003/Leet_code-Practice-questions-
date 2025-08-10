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

int ans=0;

void helper(TreeNode* root, int s){
    if(root == NULL)return;

    s = s*10 + root->val;

    if(root->left == NULL && root->right == NULL)ans = ans+s;

    helper(root->left, s);
    helper(root->right,s);
}
    int sumNumbers(TreeNode* root) {
        if(root == NULL)return 0;

        int s=0 , x=0;
        helper(root , s);

        return ans;
    }
};