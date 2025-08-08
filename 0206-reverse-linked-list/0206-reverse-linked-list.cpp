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
    ListNode* reverseList(ListNode* head) {
        if(head == NULL || head->next == NULL)return head;

        ListNode* c = head;
        ListNode* prev = NULL;
        ListNode* c_p = NULL;

        while(c){
            c_p = c->next;
            c->next = prev;
            prev = c;
            c= c_p;
        }
        return prev;
    }
};