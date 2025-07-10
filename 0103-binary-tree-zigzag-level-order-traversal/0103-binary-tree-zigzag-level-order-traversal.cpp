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
 bool flag = true;
void helper(TreeNode* root ,vector<vector<int>>& res , vector<int>& curr){
    if(root == NULL) return;

    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){

        curr.clear();
        int level = q.size();

        for(int i=0;i<level;i++){
            TreeNode* curr_n = q.front();
            q.pop();

            curr.push_back(curr_n->val);
            
            if(curr_n->left) q.push(curr_n->left);
            if(curr_n->right) q.push(curr_n->right);   
        }
        if(flag == true){
            res.push_back(curr);
            flag = false;
        }
        else{
            reverse(curr.begin(), curr.end());
            res.push_back(curr);
            flag = true;
        }
    }
}
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        vector<int>curr;

        if(root==NULL) return res;

        helper(root , res , curr);
        return res;
    }
};