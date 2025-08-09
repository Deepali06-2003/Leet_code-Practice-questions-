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
        unordered_map<Node* , Node*>map;

        
        Node* n_h = new Node(head->val);
        map[head] = n_h;

        Node* t = head->next;
        Node* nt = n_h;

        while(t){
            nt->next = new Node(t->val);
            nt = nt->next;
            
            map[t] = nt;
            t = t->next;
        }

        t = head;
        nt = n_h;

        while(t){
            Node* x = t->random;
            if(map.find(x) != map.end()){
                nt->random = map[x];
            }
            t=t->next;
            nt = nt->next;
        }

        return n_h;

    }
};