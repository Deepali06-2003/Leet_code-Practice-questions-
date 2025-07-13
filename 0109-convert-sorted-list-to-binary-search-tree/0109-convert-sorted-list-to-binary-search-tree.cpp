/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
TreeNode* helper(ListNode* head ,ListNode* tail){
    if(head == NULL) return NULL;
    if(head == tail) return NULL;

    ListNode* s = head;
    ListNode* f = head;

    while(f!= tail && f->next !=tail){
        s= s->next;
        f= f->next->next;
    }
    
    TreeNode* root = new TreeNode(s->val);
    root->left = helper(head , s);
    root->right = helper(s->next , tail);

    return root;
}
    TreeNode* sortedListToBST(ListNode* head) {
        if(head== NULL)return NULL;

        
        TreeNode* root = helper(head , NULL);
        return root;
        
    }
};