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
void helper(TreeNode* root , vector<vector<int>>&res , vector<int>&curr){
    if(root == NULL)return;

    queue<TreeNode*>q;
    q.push(root);

    while(! q.empty()){
        int l = q.size();
        curr.clear();
        for(int i =0;i<l ;i++){

            TreeNode* c = q.front();
            q.pop();

            curr.push_back(c->val);
            if(c->left) q.push(c->left);
            if(c->right) q.push(c->right);
        }
        res.push_back(curr);
    }
}
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>>res;
        vector<int>curr;

        if(root == NULL)return res;
        helper(root , res , curr);

        return res;
    }
};