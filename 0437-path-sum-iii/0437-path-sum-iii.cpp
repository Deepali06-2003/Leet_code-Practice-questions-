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
int c=0;
unordered_map<long ,int>map;
void helper(TreeNode* root, int target, long s){
    if(root == NULL)return;

    s = s+ root->val;
    if(s == target)c++;

    if(map.find(s -target) != map.end())c = c+ map[s-target];

    map[s]++;
    helper(root->left , target , s);
    helper(root->right , target , s);
    map[s]--;
}
    int pathSum(TreeNode* root, int targetSum) {
        
        helper(root , targetSum , 0);
        return c;
    }
};