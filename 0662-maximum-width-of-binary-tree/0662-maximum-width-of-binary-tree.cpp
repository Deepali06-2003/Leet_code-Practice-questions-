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

        queue<pair<TreeNode*, long>>q;
        long ans=0;

        q.push({root , 0});

        while(!q.empty()){
            int size = q.size();

            long f = q.front().second;
            long l = q.back().second;

            ans = max(ans , l-f+1);

            for(int i =0;i<size;i++){

                auto temp = q.front();
                q.pop();

                long index = temp.second - f;

                if(temp.first->left) q.push({temp.first->left, 2*index+1 });
                if(temp.first->right) q.push({temp.first->right, 2*index+2 });
            }
        }

        return (int)ans;
    }
};