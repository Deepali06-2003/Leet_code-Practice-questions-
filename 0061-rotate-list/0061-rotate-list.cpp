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
        if(head == NULL)return NULL;

        ListNode* s = head;
        ListNode* f = head;

        int c=0;

        while(f){
            c++;
            f = f->next;
        }
        k = k %c;

        if(k== c || k==0)return head;

        f= head;
        while(k!=0){
            f=f->next;
            k--;
        }

        //if(f->next == NULL)return head->next;

        while(f->next != NULL){
            s=s->next;
            f=f->next;
        }
        ListNode* n_h = s->next;
        s->next = NULL;
        f->next = head;

        return n_h;
    }
};