class Solution {
public:
int helper(vector<vector<int>>& triangle , vector<vector<int>>& dp , int n  , int i , int j){
    
    if(i<0 || i>= n || j<0 || j>=n)return 0;
    
    if(i == (n-1)) return triangle[i][j];

    if(dp[i][j] != INT_MAX)return dp[i][j];

    int a = triangle[i][j] + helper(triangle , dp , n  , i+1 , j);
    int b = triangle[i][j] + helper(triangle , dp , n , i+1 , j+1);

    return dp[i][j] = min(a , b);
}
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();

        vector<vector<int>>dp(n , vector<int>(n , INT_MAX));

        int res = helper(triangle , dp ,n , 0 , 0);
        return res;
       
    }
};