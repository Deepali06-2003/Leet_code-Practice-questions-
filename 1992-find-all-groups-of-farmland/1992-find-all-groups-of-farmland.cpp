class Solution {
public:
    void dfs(vector<vector<int>>& land, int i, int j, int n, int m, vector<int>& curr, int& max_i, int& max_j) {
        if (i < 0 || j < 0 || i >= n || j >= m || land[i][j] == 0) return;

        land[i][j] = 0;
        max_i = max(max_i, i);
        max_j = max(max_j, j);

        dfs(land, i + 1, j, n, m, curr, max_i, max_j);
        dfs(land, i, j + 1, n, m, curr, max_i, max_j);
    }

    vector<vector<int>> findFarmland(vector<vector<int>>& land) {
        int n = land.size();
        int m = land[0].size(); 
        vector<vector<int>> res;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (land[i][j] == 1) {
                    vector<int> curr = {i, j};
                    int max_i = i, max_j = j;
                    dfs(land, i, j, n, m, curr, max_i, max_j);
                    curr.push_back(max_i);
                    curr.push_back(max_j);
                    res.push_back(curr);
                }
            }
        }

        return res;
    }
};