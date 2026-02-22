/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL)return NULL;

        unordered_map<Node* , Node*>mp;
       
        Node* newH = new Node(head->val);
        mp[head] = newH;

        Node* temp = head->next;
        Node* t= newH;

        while(temp != NULL){
            Node* x = new Node(temp->val);
            mp[temp] = x;
            temp = temp->next;

            t->next = x;
            t = t->next;
        }
        temp = head;
        t = newH;
        while(temp != NULL){
            Node* x = temp->random;

            if(mp.find(x) != mp.end()) t->random = mp[x];
            t = t->next;
            temp = temp->next;
        }
        return newH;
    }
};