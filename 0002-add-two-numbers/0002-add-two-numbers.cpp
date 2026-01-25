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
        ListNode * lhead = new ListNode(0);
        ListNode* l3= lhead;
        if(l1 == NULL ){
            return l2;
        }
        if(l2== NULL){
            return l1;
        }

        int s=0;
        int c=0;
        int v=0;
        while(l1!=NULL || l2!= NULL){
            if(l1!= NULL){
                s = s+ l1->val;
                l1 = l1->next;
            }
            if(l2!=NULL){
                s = s+ l2->val;
                l2 = l2->next;
            }
            
            

            v= s%10;
            ListNode* v1 = new ListNode(v);
            s = s/10;

            l3->next = v1;
            l3 = l3->next;

        }
        if(s!=0){
            l3->next = new ListNode(s);
        }
        


        return lhead->next;
    }
};