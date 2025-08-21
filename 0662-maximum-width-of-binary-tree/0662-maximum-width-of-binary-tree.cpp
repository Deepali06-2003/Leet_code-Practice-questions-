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
    int widthOfBinaryTree(TreeNode* root) {
        if(root == NULL)return 0;

        long ans=0;
        queue<pair<TreeNode* , long>>q;
        q.push({root, 0});

        while(!q.empty()){
            int s = q.size();

            long f = q.front().second;
            long l = q.back().second;

            ans = max(ans, l-f + 1);
            for(int i =0;i<s;i++){
                auto node = q.front();
                q.pop();

                long index = node.second- f;

                if(node.first->left) q.push({node.first->left, 2*index+1});
                if(node.first->right) q.push({node.first->right , 2*index+2});
            }
        }
        return (int)ans;
    }
};