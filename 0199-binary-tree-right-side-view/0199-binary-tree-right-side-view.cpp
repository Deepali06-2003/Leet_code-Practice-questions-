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
void helper(TreeNode* root ,vector<int>& res, vector<int>& curr){
    if(root == NULL)return;

    queue<TreeNode*>q;
    q.push(root);

    while(!q.empty()){
        int l  = q.size();
        curr.clear();

        for(int i =0;i<l;i++){
            TreeNode* temp = q.front();
            q.pop();

            curr.push_back(temp->val);

            if(temp->left) q.push(temp->left);
            if(temp->right) q.push(temp->right);
        }

        res.push_back(curr.back());
    }

}
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        vector<int>curr;

        if(root == NULL)return res;

        helper(root , res , curr);
        return res;
    }
};