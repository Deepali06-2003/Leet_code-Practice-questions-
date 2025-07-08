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
void helper(TreeNode* root , vector<int>& res , int c){
    if(root == NULL){
        c = INT_MAX;
        return;
        
    }
    if(root!= NULL)
        c++;

    if(root->left == NULL && root->right == NULL){
        res.push_back(c);
    }

    helper(root->left , res , c);
    helper(root->right , res , c);
}
    int minDepth(TreeNode* root) {
        if(root== NULL){
            return 0;
        }
        vector<int>res;
        helper(root , res , 0);

        sort(res.begin(), res.end());
        return res[0];
        
        
    }
};