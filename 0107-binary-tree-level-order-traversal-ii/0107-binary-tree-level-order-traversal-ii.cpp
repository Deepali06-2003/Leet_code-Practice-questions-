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
void helper(TreeNode* root ,vector<vector<int>>&res , vector<int>&curr ){
    if(root == NULL)return;

    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){

        curr.clear();
        int l = q.size();

        for(int i=0 ;i<l;i++){
            TreeNode* temp = q.front();
            q.pop();

            curr.push_back(temp->val);
            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }
        res.push_back(curr);
    }

}
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>>res;
        vector<int>curr;

        if(root == NULL)return res;

        helper(root , res , curr);
        
        reverse(res.begin(), res.end());
        return res;
    }
};