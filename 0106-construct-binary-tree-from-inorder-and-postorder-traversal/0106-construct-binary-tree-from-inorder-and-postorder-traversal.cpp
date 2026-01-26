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
TreeNode* helper(vector<int>& inorder , int in_s , int in_e , vector<int>& postorder , int pos_s , int pos_e){

    if(in_s > in_e || pos_s > pos_e){
        return NULL;
    }

    TreeNode* root = new TreeNode(postorder[pos_e]);

    int root_index = in_s;
    while(root_index <= in_e && inorder[root_index] != root->val){
        root_index+= 1;
    }
    int left_size = root_index - in_s;

    root->left = helper(inorder , in_s , root_index-1 , postorder , pos_s, pos_s+left_size-1);

    root->right = helper(inorder , root_index+1 , in_e , postorder , pos_s+left_size , pos_e-1);

    return root;
}
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder , 0 , inorder.size()-1 , postorder , 0 , postorder.size()-1);
    }
};