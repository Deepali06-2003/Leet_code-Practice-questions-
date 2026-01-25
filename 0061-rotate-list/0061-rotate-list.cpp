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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* s = head;
        ListNode* f = head;

        if(head == NULL || k==0)return head;
       
       int c=0;
        while(f!=NULL){
            c++;
            f = f->next;
        }

        f = head;
        k = k%c;
        if(k==0 || k ==c)return head;

        while(k!=0){
            f=f->next;
            k--;
        }

        while(f->next != NULL){
            s= s->next;
            f = f->next; 
        }   

        ListNode* t = s->next;
        s->next = NULL;
        f->next = head;

        return t;
    }
};