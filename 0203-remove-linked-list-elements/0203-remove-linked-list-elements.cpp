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
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL){
            return NULL;
        }
        if(head->val == val && head->next == NULL){
            return NULL;
        }
        ListNode* lhead = new ListNode(0);
        ListNode* l = lhead;

        ListNode* temp = head;
        
        while(temp != NULL){
            if(temp->val == val){
                
                temp = temp->next;
            }
            else{
                l->next = temp;
                l= l->next;
                temp = temp->next;
            }
        }
        l->next = NULL;
        return lhead->next;


        
    }
};