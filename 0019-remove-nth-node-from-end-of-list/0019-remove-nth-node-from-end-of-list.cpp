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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* f= head;
        ListNode* s= head;

int c=0;
if(k==0 || head== NULL){
    return head;
}
        while(f!=NULL){
            c++;
            f= f->next;
        }

        k = k%c;
        f=head;
        while(k!=0){
            f=f->next;
            k--;
        }

        while(f!=NULL){
            s=s->next;
            f=f->next;
        }

        s->next = s->next->next;
        return head;


    }
};