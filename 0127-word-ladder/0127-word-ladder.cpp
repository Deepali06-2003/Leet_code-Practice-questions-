class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<pair<string, int>>q;
        unordered_set<string >st(wordList.begin(), wordList.end());

        q.push({beginWord , 1});
        st.erase(beginWord);

        while(!q.empty()){

            string x = q.front().first;
            int step = q.front().second;

            q.pop();
            if(x == endWord)return step;

            for(int i = 0; i < x.size(); i++) {
                char original = x[i];

                for(char j = 'a'; j <= 'z'; j++) {
                    if(j == original) continue;

                    x[i] = j;

                    if(st.find(x) != st.end()) {
                        st.erase(x);
                        q.push({x, step + 1});
                    }
                }

                x[i] = original;
            }
        }

        return 0;

    }
};