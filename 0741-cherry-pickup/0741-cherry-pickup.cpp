class Solution {
public:
int n;
    vector<vector<vector<int>>> dp;
    
    int dfs(vector<vector<int>>& grid, int r1, int c1, int r2) {
        int c2 = r1 + c1 - r2;
        
        if(r1 >= n || c1 >= n || r2 >= n || c2 >= n) return -1e9; // invalid
        if(grid[r1][c1] == -1 || grid[r2][c2] == -1) return -1e9; // thorn
        
        if(r1 == n-1 && c1 == n-1) return grid[r1][c1]; // reached end
        
        if(dp[r1][c1][r2] != INT_MIN) return dp[r1][c1][r2];
        
        int cherries = 0;
        if(r1 == r2 && c1 == c2) cherries += grid[r1][c1];
        else cherries += grid[r1][c1] + grid[r2][c2];
        
        int best = max({
            dfs(grid, r1+1, c1, r2+1), // both down
            dfs(grid, r1, c1+1, r2),   // A right, B down
            dfs(grid, r1+1, c1, r2),   // A down, B right
            dfs(grid, r1, c1+1, r2+1)  // both right
        });
        
        cherries += best;
        return dp[r1][c1][r2] = cherries;
    }
    
    int cherryPickup(vector<vector<int>>& grid) {
        n = grid.size();
        dp.assign(n, vector<vector<int>>(n, vector<int>(n, INT_MIN)));
        return max(0, dfs(grid, 0, 0, 0));
    }
};