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
    ListNode* partition(ListNode* head, int x) {
        ListNode* temp = head;
        
        ListNode* lhead = new ListNode(0);
        ListNode* ghead =new ListNode(0);

        ListNode* l = lhead;
        ListNode* g = ghead;

        if(head == NULL){
            return head;
        }

        while(temp != NULL){
            if(temp->val < x){
                l->next = temp;
                l = l->next;

            }
            else{
                g->next = temp;
                g = g->next;
            }
            temp = temp->next;
        }
       // lhead = lhead->next;
        
        g->next = NULL;
        l->next = ghead->next;
         ghead->next = NULL;   
        return lhead->next;
    }
};