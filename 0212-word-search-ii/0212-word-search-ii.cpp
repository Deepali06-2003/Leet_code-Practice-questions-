class Solution {
public:
int n , m;
vector<string>res;

struct trieNode{
    string word;
    bool endW;
    trieNode* child[26];

    trieNode(){
        word = "";
        endW = false;
        for(int i=0;i<26;i++) child[i]=NULL;
    }
};

void insert(trieNode* root , string & w){
    trieNode* t = root;

    for(char c : w){
        if(t->child[c-'a'] == NULL){
            t->child[c-'a'] = new trieNode();
        }
        t = t->child[c-'a'];
    }

    t->word = w;
    t->endW = true;
}

void dfs(vector<vector<char>>& board, trieNode* root , int i , int j){

    if(i<0 || j<0 || i>=n || j>=m)return;
    char c = board[i][j];
    if(c == '$' || root->child[c-'a'] == NULL)return;

    root = root->child[c-'a'];

    if(root->endW == true){
        res.push_back(root->word);
        root->endW = false;
    }

    board[i][j]='$';

    dfs(board, root, i+1 , j);
    dfs(board, root, i -1, j);
    dfs(board, root, i , j+1);
    dfs(board, root, i , j-1);

    board[i][j]= c;
}
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        n = board.size(), m = board[0].size();

        trieNode* root = new trieNode();
        for(string w : words) insert(root, w);

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                dfs(board, root, i , j);
            }
        }
        return res;
    }
};