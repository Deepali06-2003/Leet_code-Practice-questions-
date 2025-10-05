class Solution {
public:
int helper(vector<vector<int>>& grid , vector<vector<vector<int>>>& dp , int n ,int r1 , int c1 , int r2){

    int c2 = r1+c1-r2;

    if(r1 >= n || c1 >= n || r2 >= n || c2>= n || grid[r1][c1]== -1 || grid[r2][c2] == -1)return -1e9;

    if(r1 == n-1 && c1 == n-1)return grid[r1][c1];
    if(dp[r1][c1][r2] != INT_MIN)return dp[r1][c1][r2];

    int t_cherry =0;
    if(r1 == r2 && c1== c2)t_cherry += grid[r1][c1];
    else t_cherry += grid[r1][c1] + grid[r2][c2];

    int best = max({
        helper(grid , dp ,n, r1+1 , c1 , r2+1),
        helper(grid , dp ,n, r1 , c1+1 , r2),
        helper(grid , dp ,n, r1+1 , c1 , r2),
        helper(grid , dp ,n, r1 , c1+1 , r2+1)
    });

    t_cherry = t_cherry + best;
    return dp[r1][c1][r2] = t_cherry;
}
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n , vector<vector<int>>(n , vector<int>(n , INT_MIN)));

        return max(0 , helper(grid , dp ,n, 0,0, 0));
    }
};