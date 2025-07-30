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
int s = 0;
void helper(TreeNode* root , int l , int h){
    if(root == NULL)return;

    if(root->val>= l && root->val <= h){
        s= s+ root->val;
    }
    if(root->val >h){
        helper(root->left , l,h);
    }
    else if(root->val < l){
        helper(root->right , l , h);
    }
    else{
        helper(root->left , l,h);
        helper(root->right , l , h);
    }
   

}
    int rangeSumBST(TreeNode* root, int low, int high) {
        if(root == NULL) return 0;

        helper(root , low , high);
        return s;
    }
};