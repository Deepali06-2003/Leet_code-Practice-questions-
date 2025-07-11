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
TreeNode* helper(vector<int>& preorder , int pre_s , int pre_end , vector<int>&inorder , int in_s , int in_end){
    if(pre_s > pre_end || in_s > in_end) return NULL;

    TreeNode* root = new TreeNode(preorder[pre_s]);

    int root_index = in_s;
    while(root_index<= in_end && root->val != inorder[root_index]) root_index++;

    int left_size = root_index- in_s;
    root->left = helper(preorder , pre_s+ 1 , pre_s+left_size , inorder , in_s , root_index-1);

    root->right = helper(preorder , pre_s+left_size+1 , pre_end , inorder , root_index+1 , in_end);

    return root;

}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(preorder.size()==0 ) return NULL;
        return helper(preorder , 0 ,preorder.size()-1 , inorder, 0 , inorder.size()-1);
    }
};