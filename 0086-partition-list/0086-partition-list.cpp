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
        if(head == NULL || head->next==NULL )return head;

        ListNode* ln = new ListNode(0);
        ListNode* gn= new ListNode(0);
        ListNode* l = ln;
        ListNode* g = gn;

        while(head){
            if(head->val < x){
                l->next = head;
                l = l->next;
            }
            else{
                g->next = head;
                g = g->next;
            }
            head = head->next;
        }

        g->next = NULL;
        l->next = gn->next;

        return ln->next;
    }
};