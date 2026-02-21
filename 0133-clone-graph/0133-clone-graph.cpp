/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
unordered_map<Node* , Node*>mp;
void dfs(Node* old_n , Node* new_n){

    for(Node* n : old_n->neighbors){

        if(mp.find(n) == mp.end()){
            
            Node* clone = new Node(n->val);
            mp[n] = clone;

            new_n->neighbors.push_back(clone);
            dfs(n , clone);
        }
        else{
            new_n->neighbors.push_back(mp[n]);
        }
    }
}

    Node* cloneGraph(Node* node) {
        if(node == NULL)return NULL;

        mp.clear();
        Node* newNode = new Node(node->val);
        mp[node] = newNode;

        dfs(node , newNode);
        return newNode;
    }
};