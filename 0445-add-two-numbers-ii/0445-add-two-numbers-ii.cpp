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
    if(head== NULL) return NULL;
    ListNode* prev = NULL;
    ListNode* curr = head;
    ListNode* n_curr= NULL;

    while(curr){
        n_curr = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n_curr;
    }
    return prev;
}
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        if(l1== NULL && l2 == NULL) return NULL;
        if(l1 == NULL) return l2;
        if(l2 == NULL) return l1;

        ListNode* list1 = reverse(l1);
        ListNode* list2 = reverse(l2);

        int s=0;
        ListNode* lhead = new ListNode(0);
        ListNode* l = lhead;

        while(list1 != NULL || list2 != NULL){
            if(list1!= NULL){
                s= s+ list1->val;
                list1 = list1->next;
            } 
            if(list2!= NULL){
                s= s+ list2->val;
                list2 = list2->next;
            }
            l->next = new ListNode(s%10);
            l = l->next;
            s= s/10;
        }
        if(s!= 0){
            l->next = new ListNode(s);
        }
        lhead = lhead->next;
        ListNode* list = reverse(lhead);

        return list;

        
    }
};