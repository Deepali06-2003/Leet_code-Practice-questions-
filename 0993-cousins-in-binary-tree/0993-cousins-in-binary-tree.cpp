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
int helper(TreeNode* root , int a , int& ans){
    if(root == NULL)return 0;

    if(root->val == a)return ans;
    
    int lh = helper(root->left , a , ans);
    int rh = helper(root->right , a , ans);

    return max(lh, rh)+1;
}
    bool isCousins(TreeNode* root, int x, int y) {
        if(root == NULL)return false;

        int ans1 = 0 , ans2 =0;
        ans1= helper(root , x, ans1);
        ans2 = helper(root , y , ans2);

        if(ans1 == ans2)return true;

        return false;
    }
};