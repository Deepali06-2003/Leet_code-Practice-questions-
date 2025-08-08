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
        if(head == NULL )return NULL;

        ListNode* f = head;
        ListNode* prev = NULL;
        ListNode* s= head;

        while(n!=0){
            f=f->next;
            n--;
        }
        if(f==NULL)return head->next;

        while(f){
            prev = s;
            s= s->next;
            f=f->next;
        }

        prev->next = s->next;
        return head;
    }
};