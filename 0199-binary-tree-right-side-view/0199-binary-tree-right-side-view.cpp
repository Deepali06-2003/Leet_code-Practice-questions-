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
void helper(TreeNode* root , vector<int>&res , int h){
    if(root == NULL){
        return;
    }
    
    if(h== res.size()){
        res.push_back(root->val);
    }

    helper(root->right, res , h+1);
    helper(root->left, res , h+1);
}
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        if(root == NULL){
            return res;
        }

        helper(root , res, 0);

        return res;
    }
};