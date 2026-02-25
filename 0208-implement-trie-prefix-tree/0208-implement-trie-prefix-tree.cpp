class Trie {
public:

struct T{
    T* child[26];
    bool isEnd;
    
    T(){
        for(int i=0;i<26;i++)child[i] = NULL;
        isEnd = false;
    }
};
T * root ;

    Trie() {
        root = new T();
    }
    

    void insert(string word) {
        T* temp = root;
         
        for(char c : word){
            if(temp->child[c-'a'] == NULL){
                temp->child[c-'a'] = new T();
            }
            temp = temp->child[c-'a'];
        }
        temp->isEnd = true;
    }



    
    bool search(string word) {
        T* temp = root;
        for( char c : word){
            if(temp->child[c-'a'] == NULL) return false;

            temp = temp->child[c-'a'];
        }
        if(temp->isEnd) return true;
        return false;
    }

    
    bool startsWith(string prefix) {
        T* temp = root;
        for( char c : prefix){
            if(temp->child[c-'a'] == NULL) return false;

            temp = temp->child[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */