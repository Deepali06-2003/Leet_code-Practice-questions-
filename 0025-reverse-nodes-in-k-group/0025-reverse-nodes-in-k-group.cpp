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
    ListNode* n_c = NULL;

    while(curr){
        n_c = curr->next;
        curr->next = prev;
        prev = curr;
        curr = n_c;
    }
    return prev; 
}

ListNode* get_K(ListNode* temp , int k){
    k = k-1;
    while(temp!= NULL && k>0){
        k--;
        temp = temp->next;
    }
    return temp;
}

    ListNode* reverseKGroup(ListNode* head, int k) {
        if(head == NULL)return NULL;

        ListNode* temp = head;
        ListNode* prev_l = NULL;

        while(temp != NULL){
            ListNode* k_n = get_K(temp , k);

            if(k_n == NULL){
                if(prev_l)prev_l->next = temp;

                break;
            }

            ListNode* next_n = k_n->next;
            k_n->next = NULL;

            reverse(temp);

            if(temp==head){
                head = k_n;
            }
            else{
                prev_l->next = k_n;
            }
            prev_l = temp;
            temp = next_n;
        }
        return head;

    }
    
};