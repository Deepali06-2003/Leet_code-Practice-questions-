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

ListNode* merge(ListNode* l1 , ListNode* l2){

    ListNode* t_h = new ListNode(0);
    ListNode* t = t_h;

    while(l1 != NULL && l2 != NULL){
        if(l1->val <= l2->val){
            t->next = l1;
            l1 = l1->next;
            t = t->next;
        }
        else{
            t->next = l2;
            l2 = l2->next;
            t = t->next;
        }
    }
    if(l1 != NULL){
        t->next = l1;
    }
    if(l2 != NULL){
        t->next = l2;
    }
    return t_h->next;
}


    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty())return NULL;
        
        ListNode* r = lists[0];
        for(int i =1;i<lists.size();i++){
            r = merge(r, lists[i]);
        }
        return r;
    }
};