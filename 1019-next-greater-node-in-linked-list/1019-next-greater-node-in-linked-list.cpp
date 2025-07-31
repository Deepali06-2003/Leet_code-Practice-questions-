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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int>res;

        if(head== NULL)return res;

        ListNode* curr = head;

        while(curr){

            int x = curr->val;
            ListNode* c = curr->next;
            bool found = false;
           
            while(c){
                if(c->val > x){
                    
                    res.push_back(c->val);
                    found= true;
                    break;
                }
                c= c->next;
            }
            if (!found) res.push_back(0);
            curr = curr->next;
        }

        return res;
    }
};