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
void helper(TreeNode* root, vector<int>& res){
    if( root== NULL)return;

    helper(root->left , res);
    res.push_back(root->val);
    helper(root->right , res);
}
    int getMinimumDifference(TreeNode* root) {
        vector<int>res;
        if(root == NULL)return -1;

        helper(root, res);

        int ans =INT_MAX;

        for(int i =1;i<res.size();i++){
            int x = abs(res[i]- res[i-1]);
            ans = min(ans , x);
        }
        return ans;
    }
};