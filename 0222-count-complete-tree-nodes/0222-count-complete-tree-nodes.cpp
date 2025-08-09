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
void helper(TreeNode* root , int& c){
    if(root == NULL)return;

    helper(root->left , c);
    c++;
    helper(root->right , c);
}
    int countNodes(TreeNode* root) {
        if(root == NULL)return 0;

        int c=0;
        helper(root , c);

        return c;
    }
};