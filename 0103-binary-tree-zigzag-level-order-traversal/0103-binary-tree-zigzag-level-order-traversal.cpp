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
void helper(TreeNode* root , vector<vector<int>>& res , vector<int>& curr){
    if(root == NULL)return;

    queue<TreeNode*>q;

    q.push(root);
    while(!q.empty()){
        int level = q.size();
        curr.clear();
        for(int i=0;i<level ;i++){
            TreeNode* n = q.front();
            q.pop();

            curr.push_back(n->val);

            if(n->left) q.push(n->left);
            if(n->right) q.push(n->right);
        }
        if(flag == true){
            flag = false;
            res.push_back(curr);
        }
        else{
            flag = true;
            reverse(curr.begin(), curr.end());
            res.push_back(curr);
        }

    }
}
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>>res;
        vector<int>curr;
        if(root == NULL)return res;

        helper(root , res , curr);
        return res;
    }
};