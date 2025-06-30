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
    ListNode* rotateRight(ListNode* head, int k) {
        ListNode* s=head;
        ListNode* f= head;

        int c=0;
        if(k==0){
            return head;
        }
        if(head==NULL){
            return head;
        }

        while(f!=NULL){
            c++;
            f=f->next;
        }
        if(k>c)
        k = k%c;
        if(k==0){
            return head;
        }
        if(head==NULL){
            return head;
        }
        if(k==c){
            return head;
        }
        if(head->next == NULL){
            return head;
        }
        

       
        
        

        f= head;
        while(k!=0){
            f=f->next;
            k--;
        }

        while(f->next!=NULL){
            s= s->next;
            f= f->next;
        }
        
        ListNode* temp = s->next;
       
        f->next = head;
        s->next = NULL;
        head = temp;

        return head;




    }
};