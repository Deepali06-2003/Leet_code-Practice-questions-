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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* temph = new ListNode(0);
        ListNode* temp = temph;

        if(l1 == NULL && l2 == NULL)return NULL;
        if(l1 == NULL)return l2;
        if(l2 == NULL)return l1;

        int x =0;

        while(l1 != NULL || l2!= NULL){

            if(l1 != NULL){
                x = x+ l1->val;
                l1 = l1->next;
            }
            if(l2 != NULL){
                x= x+ l2->val;
                l2 = l2->next;
            }

            temp->next = new ListNode(x%10);
            x= x/10;
            temp = temp->next;
        }
        if(x!= 0){
            temp->next = new ListNode(x);
            temp = temp->next;
        }
        return temph->next;
    }
};