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


    int maxDepth(TreeNode* root) {
        int c=0;
         if(root== NULL){
        return 0;
    }
    if(root!= NULL){
        c=c+1;
    }
    int res = max( maxDepth(root->left) , maxDepth(root->right) );
    return res+1;
    
    }
};