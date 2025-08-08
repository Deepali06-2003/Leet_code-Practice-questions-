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

        Node* temp = head;
        unordered_map<Node* , Node*>map;

        Node* n_head = new Node(head->val);
        map[head] = n_head;
        temp = temp->next;

        Node* n_temp = n_head;

        while(temp){
            Node* x= new Node(temp->val);
            n_temp->next = x;
            
            n_temp = n_temp->next;
            map[temp] = n_temp;

            temp = temp->next;
        }

        n_temp = n_head;
        temp = head;
        while(temp){
            Node* x = temp->random;
            if(map.find(x) != map.end()){
                //cout<<x->val<<" ";
                n_temp->random = map[x];
            }

            n_temp = n_temp->next;
            temp = temp->next;
        }
        for(auto i : map){
            cout<<i.first <<" "<<i.second<<"\n";
        }

        return n_head;
    }
};