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
    
    ListNode* curr = head;
    ListNode* prev = NULL;
    ListNode* curr_n= NULL;
    while(curr!= NULL){
        curr_n= curr->next;
        curr->next = prev;
        prev= curr;
        curr = curr_n;
    }
    return prev;
}
    bool isPalindrome(ListNode* head) {
        if(head ==NULL|| head->next == NULL){
        return true;
    }
        ListNode* s = head;
        ListNode* f = head;
        ListNode* prev = NULL;
        while(f!= NULL && f->next != NULL){
            prev = s;
            s= s->next;
            f = f->next->next;
        }
    
        ListNode* l2 = reverse(s);
        prev->next = NULL;
        
       

        while(head!= NULL && l2!= NULL){
            if(head->val != l2->val){
                return false;
            }
            head = head->next;
            l2 = l2->next;
        }
        return true;
    }
};