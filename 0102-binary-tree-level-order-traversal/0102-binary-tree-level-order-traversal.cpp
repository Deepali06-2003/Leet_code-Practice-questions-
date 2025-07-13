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
void helper(TreeNode* root , vector<vector<int>>&res , vector<int>curr){
    if(root== NULL)return;

    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        curr.clear();
        int level = q.size();
        for(int i=0;i<level;i++){
            TreeNode* cur_n = q.front();
            q.pop();
            curr.push_back(cur_n->val);

            if(cur_n->left) q.push(cur_n->left);
            if(cur_n->right) q.push(cur_n->right);
        }
        res.push_back(curr);
    }
    
}
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> curr;
        if(root == NULL) return res;

        helper(root , res , curr);
        return res;
    }
};