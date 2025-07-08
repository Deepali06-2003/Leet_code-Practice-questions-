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
int maxTree(TreeNode* root , int m){
    if (root == NULL) return m;
    m = max(m, root->val);
    return maxTree(root->right , m);

}
int minTree(TreeNode* root , int mi){
    if(root== NULL) return mi;
    mi = min(root->val , mi);
    return minTree(root->left , mi);
}

    bool isValidBST(TreeNode* root) {
        if(root== NULL){
            return true;
        }
        
        if(root->left != NULL){
            //find max of root->left
            
            int leftChild = maxTree(root->left , INT_MIN);
            if(leftChild >= root->val ) return false;
        }
        if(root->right != NULL){
            //find min of root->right
            int mi = INT_MAX;
            int rightChild = minTree(root->right , mi);
            if(rightChild <= root->val ) return false;
        }



        return isValidBST(root->left) && isValidBST(root->right);
    }
};