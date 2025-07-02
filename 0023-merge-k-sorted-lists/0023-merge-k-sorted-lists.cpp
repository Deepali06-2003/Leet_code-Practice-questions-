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
ListNode* mergell(ListNode*l1 , ListNode* l2){
    ListNode* lhead = new ListNode(0);
    ListNode* l3= lhead;
    while(l1!=NULL && l2!= NULL){
        if(l1->val <= l2->val){
            l3->next = l1;
            l1= l1->next;
        }
        else{
            l3->next = l2;
            l2= l2->next;
        }
        l3= l3->next;
    }
    while(l1!=NULL){
        l3->next = l1;
            l1= l1->next;
            l3= l3->next;
    }
    while(l2!=NULL){
        l3->next = l2;
            l2= l2->next;
            l3= l3->next;
    }

    return lhead->next;
}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        
        ListNode* h= NULL;

        for(int i =0;i<lists.size(); i++){
            h = mergell(h , lists[i]);
        }

        return h;


        
    }
};