class Solution {
public:
    vector<string> res;
    int n, m;

    struct trieNode {
        string word;
        bool endWord;
        trieNode* child[26];

        trieNode() {
            word = "";
            endWord = false;
            for(int i = 0; i < 26; i++)
                child[i] = NULL;
        }
    };

    void insert(trieNode* root, string& w) {
        trieNode* t = root;

        for(char c : w) {
            if(t->child[c - 'a'] == NULL)
                t->child[c - 'a'] = new trieNode();
            t = t->child[c - 'a'];
        }

        t->word = w;
        t->endWord = true;
    }

    void dfs(trieNode* node, vector<vector<char>>& board, int i, int j) {

        if(i < 0 || j < 0 || i >= n || j >= m)
            return;

        char c = board[i][j];
        if(c == '$' || node->child[c - 'a'] == NULL)
            return;

        node = node->child[c - 'a'];

        if(node->endWord) {
            res.push_back(node->word);
            node->endWord = false;
        }

        board[i][j] = '$';

        dfs(node, board, i + 1, j);
        dfs(node, board, i - 1, j);
        dfs(node, board, i, j + 1);
        dfs(node, board, i, j - 1);

        board[i][j] = c;
    }

    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {

        res.clear();
        n = board.size();
        m = board[0].size();

        trieNode* root = new trieNode();

        for(string& w : words)
            insert(root, w);

        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                dfs(root, board, i, j);
            }
        }

        return res;
    }
};
