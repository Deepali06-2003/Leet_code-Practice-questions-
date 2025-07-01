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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* lhead= new ListNode(0);
        ListNode* l3 = lhead;

        while(list1 != NULL && list2!= NULL){
            if(list1->val <= list2->val){
                l3->next = list1;
                list1= list1->next;
                l3 = l3->next;
            }
            else{
                l3->next = list2;
                list2 = list2->next;
                l3 = l3->next;
            }



        }
        while(list1!= NULL){
            l3->next = list1;
            l3= l3->next;
            list1 = list1->next;
        }

        while(list2!= NULL){
            l3->next = list2;
            l3= l3->next;
            list2= list2->next;
        }

        return lhead->next;
    }
};