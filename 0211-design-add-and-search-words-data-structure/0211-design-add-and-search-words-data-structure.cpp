class WordDictionary {
public:
struct Trie{
    Trie* child[26];
    bool isEnd;

    Trie(){
        for(int i=0;i<26;i++)child[i] = NULL;
        isEnd = false;
    }
};

Trie * root;
    WordDictionary() { root = new Trie(); }
    
    void addWord(string word) {
        Trie* temp = root;
        
        for(char c: word){
            if(temp->child[c-'a'] == NULL) temp->child[c-'a'] = new Trie();

            temp = temp->child[c-'a'];
        }
        temp->isEnd = true;
    }
    
bool helper(Trie* root, string word){
    Trie* temp = root;

    for(int i=0 ;i< word.size();i++){
        char c = word[i];

        if(c == '.'){
            for(int j =0; j<26 ;j++){
                if(temp->child[j] != NULL){
                   if( helper(temp->child[j], word.substr(i+1)) )return true;
                }
            }
            return false;
        }
        else if(temp->child[c-'a'] == NULL)return false;

        temp = temp->child[c-'a'];
    }

    if(temp->isEnd)return true;
    return false;
}

    bool search(string word) {

    Trie* temp = root;
    return helper(root , word);  
    }
};

/**
 * Your WordDictionary object will be instantiated and called as such:
 * WordDictionary* obj = new WordDictionary();
 * obj->addWord(word);
 * bool param_2 = obj->search(word);
 */