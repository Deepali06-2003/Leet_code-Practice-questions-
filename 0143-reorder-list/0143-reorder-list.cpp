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

ListNode* reverse(ListNode* head){
    if(head==NULL || head->next==NULL)return head;

    ListNode* prev= NULL;
    ListNode* curr = head;
    ListNode* n_c= NULL;

    while(curr != NULL){
       n_c= curr->next;
       curr->next = prev;
       prev = curr;
       curr = n_c;
    }return prev;
}


    void reorderList(ListNode* head) {
        if(head==NULL || head->next==NULL || head->next->next==NULL)return;

        ListNode* s= head;
        ListNode* f=head;
        ListNode* l1= head;
        

        while(f!=NULL && f->next!=NULL){
            s=s->next;
            f= f->next->next;
        }

        ListNode* l2= s->next;
        s->next = NULL;

        l2= reverse(l2);

        while(l2!=NULL){
            
            ListNode* l1_n = l1->next;
            ListNode* l2_n = l2->next;

            l1->next = l2;
            l2->next = l1_n;

            l1 = l1_n;
            l2= l2_n;
        }
    }
};