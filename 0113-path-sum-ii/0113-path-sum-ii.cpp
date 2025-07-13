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
void helper(TreeNode* root , int target , vector<vector<int>>& res ,vector<int> curr , int x){
    
    if(root == NULL){
        return;
    }

    x= x + root->val;
    curr.push_back(root->val);

    if(root->left == NULL && root->right == NULL){
        if(x == target){
            res.push_back(curr);
        }
    }
    //else{
        helper(root->left , target , res ,curr, x);
        helper(root->right , target , res ,curr, x);
        
    //}
    curr.pop_back();
        
    
    
}

    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> curr;
        if(root== NULL && 0 == targetSum){
            return res;
        }
        
        helper(root , targetSum , res,curr , 0);

        return res;
        
    }
};