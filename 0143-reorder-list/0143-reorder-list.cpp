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
 ListNode* reverse(ListNode* head){
    //reverse list2 having head = headB.
        ListNode* curr= head;
        ListNode* prev = NULL;
        ListNode* curr_n= NULL;

        while(curr!= NULL){
            curr_n = curr->next;
            curr->next = prev;
             prev = curr;
             curr= curr_n;
        }

    return prev;

 }
class Solution {
public:
    void reorderList(ListNode* head) {
        if(head == NULL || head->next == NULL){
            return ;
        }

        ListNode* s = head;
        ListNode* f= head;
        

        
        while(f!= NULL && f->next != NULL){
            s= s->next;
            f= f->next ->next;
        }

        ListNode* headB =NULL;
        headB= reverse(s->next);
        s->next = NULL;

        

        //merge lis1 (head == head)and list2(headB)
        ListNode* curr1 = head;
        ListNode* curr2 = headB;
        while(curr2!=NULL){
            ListNode* cn1 = curr1->next;
            ListNode* cn2 = curr2->next;

            curr1->next = curr2;
            curr2->next = cn1;

            curr1 = cn1;
            curr2= cn2;
        }

    }
};