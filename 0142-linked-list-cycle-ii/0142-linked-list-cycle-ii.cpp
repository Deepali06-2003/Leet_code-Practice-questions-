/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        ListNode* s = head ;
        ListNode* f = head;

        while(f!= NULL && f->next != NULL){
            s= s->next ;
            f = f->next ->next;

            if(f==s){
                ListNode* temp = head;
                while(s!= temp){
                s = s->next;
                temp = temp->next;
                }
                return s;

            }
            
        }
        return NULL;
    }
};