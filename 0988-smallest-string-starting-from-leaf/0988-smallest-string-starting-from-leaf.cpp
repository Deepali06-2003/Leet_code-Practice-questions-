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
void helper(TreeNode* root , string& res , string curr){
    if(root == NULL){
        return ;
    }   
    curr += (char)root->val + 'a';


    if(root->left == NULL && root->right == NULL){
        reverse(curr.begin(), curr.end());

        if(res.empty() || curr < res)
            res = curr;

    }
    helper(root->left , res , curr);
    helper(root->right , res , curr);

}
    string smallestFromLeaf(TreeNode* root) {
      
        string res;
          if(root== NULL){
            return res;
        }

        helper(root , res , "");
        
        return res;
    }
};