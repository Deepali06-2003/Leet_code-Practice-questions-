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

TreeNode* helper(vector<int>& inorder, int is , int ie ,vector<int>& postorder , int ps , int pe){

    if(is> ie || ps> pe)return NULL;

    TreeNode* root = new TreeNode(postorder[pe]);

    int root_index = is;
    while(root_index <= ie && root->val != inorder[root_index] ){
        root_index++;
    }

    int left_size = root_index - is;


    root->left = helper(inorder , is , root_index-1 , postorder , ps , ps+left_size-1); 
    root->right = helper(inorder , root_index+1 , ie , postorder , ps+ left_size , pe-1);


    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if(inorder.size()==0)return NULL;

        TreeNode* root = helper(inorder , 0 , inorder.size()-1 , postorder , 0 , postorder.size()-1);

        return root;
    }
};