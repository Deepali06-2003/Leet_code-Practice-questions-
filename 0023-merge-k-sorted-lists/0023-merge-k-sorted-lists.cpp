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
    if(l1 == NULL && l2 == NULL) return NULL;
    if(l1== NULL) return l2;
    if(l2== NULL) return l1;

    ListNode* d = new ListNode(0);
    ListNode* dn = d;

    while(l1!= NULL && l2 != NULL){
        if(l1->val<= l2->val){
            dn->next = l1;
            l1= l1->next;
        }
        else{
            dn->next = l2;
            l2= l2->next;
        }
        dn = dn->next;
    }
    if(l1!= NULL){
        dn->next = l1;
        dn = dn->next;
    }
    if(l2!= NULL){
        dn->next = l2;
        dn = dn->next;
    }
    return d->next;

}
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if(lists.empty()){
            return NULL;
        }
        ListNode* ans = NULL;
        for(int i=0;i<lists.size();i++){
            ans = merge(ans , lists[i]);
        }
        return ans;
    }
};