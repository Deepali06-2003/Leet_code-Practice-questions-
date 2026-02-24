class Solution {
public:

vector<string>res;
int n =0 , m=0;

struct Trie{
    string s;
    bool isEnd;
    Trie* child[26];

    Trie(){
        s = "";
        isEnd = false;
        for(int i=0;i<26;i++) child[i]= NULL;
    }
};

void insert(Trie* root, string & word){
    Trie* t = root;
    for(char c: word){
        if(t->child[c- 'a'] == NULL){
            t->child[c- 'a'] = new Trie();
        }
        t= t->child[c - 'a'];
    }
    t->isEnd = true;
    t->s = word;
}

void dfs(Trie* root ,vector<vector<char>>& board, int i , int j){
    if(i<0 || j<0 || i>=n || j>=m)return;

    char c = board[i][j];
    if(c == '$' || root->child[c-'a'] == NULL)return;

    root = root->child[c - 'a'];
    if(root->isEnd == true){
        res.push_back(root->s);
        root->isEnd = false;
    }

    board[i][j] = '$';
    dfs(root , board , i+1 , j);
    dfs(root , board , i-1 , j);
    dfs(root , board , i , j+1);
    dfs(root , board , i , j-1);
    board[i][j]= c;
}

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        
        n = board.size();
        m = board[0].size();

        Trie *root = new Trie();

        for(string & word : words){
            insert(root , word);
        }
        for(int i =0 ;i<n;i++){
            for(int j =0;j<m;j++){

                dfs(root , board, i , j);
            }
        }
        return res;
    }
};