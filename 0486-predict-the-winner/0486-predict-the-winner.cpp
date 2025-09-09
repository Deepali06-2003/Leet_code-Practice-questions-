class Solution {
public:
int helper(vector<int>& nums , vector<vector<int>>& dp , int l , int h){
    if(l>h)return 0;
    if(dp[l][h] != INT_MIN)return dp[l][h];
    if(l==h)return nums[l];

    int i = nums[l] - helper(nums , dp , l+1 , h);
    int j = nums[h] - helper(nums , dp , l , h-1);

    return dp[l][h] = max(i , j);
}
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>>dp (n, vector<int>(n, INT_MIN));

        return helper(nums , dp , 0 , n-1)>=0;
    }
};