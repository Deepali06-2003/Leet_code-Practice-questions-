class Solution {
public:
int solve(vector<int>& nums , int l , int h, vector<vector<int>>& dp){
    if(l>h)return 0;
    if(l == h)return nums[l];

    if (dp[l][h] != INT_MIN) return dp[l][h];

    int i = nums[l] - solve(nums , l+1 , h, dp);
    int j = nums[h] - solve(nums , l , h-1, dp);

    return dp[l][h] = max(i , j);
}
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n, INT_MIN));
        return solve(nums , 0 , n-1 , dp) >=0;
    }
};