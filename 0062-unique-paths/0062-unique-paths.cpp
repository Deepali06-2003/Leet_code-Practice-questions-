class Solution {
public:
int helper(vector<vector<int>>&dp , int i , int j , int m , int n){

    if(i == (m-1) && j ==(n-1))return 1;
    if(i>(m-1) || j> (n-1))return 0;

    if(dp[i][j] != -1)return dp[i][j];

    int right = helper(dp , i , j+1 , m , n);
    int down = helper(dp , i+1 , j , m , n);

    return dp[i][j] = right + down;
}
    int uniquePaths(int m, int n) {
        vector<vector<int>> dp(m, vector<int>(n, -1));

        return helper(dp , 0 , 0 , m , n);
        
    }
};