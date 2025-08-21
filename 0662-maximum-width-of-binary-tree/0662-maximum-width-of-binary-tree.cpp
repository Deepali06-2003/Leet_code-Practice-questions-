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
         if (!root) return 0;

        long ans = 0;
        queue<pair<TreeNode*, long>> q;
        q.push({root, 0});

        while (!q.empty()) {
            int size = q.size();
            long first = q.front().second;   // leftmost index
            long last = q.back().second;     // rightmost index
            ans = max(ans, last - first + 1);

            for (int i = 0; i < size; i++) {
                auto node = q.front();
                q.pop();
                long idx = node.second - first;
                if (node.first->left) 
                    q.push({node.first->left, 2 * idx + 1});
                if (node.first->right) 
                    q.push({node.first->right, 2 * idx + 2});
            }
        }
        return (int)ans;
    }
};