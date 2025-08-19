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
void helper(TreeNode* root , string& s , string curr){
    if(root == NULL)return;

    curr = curr + char(root->val + 'a');
    if(!root->left && !root->right){
        reverse(curr.begin(), curr.end());
        if(s>curr || s.empty())s = curr;
    }

    helper(root->left , s , curr);
    helper(root->right ,s , curr);
}
    string smallestFromLeaf(TreeNode* root) {
        string s;
        string curr;
        if(root == NULL)return s;

        helper(root , s , curr);

        return s;

    }
};