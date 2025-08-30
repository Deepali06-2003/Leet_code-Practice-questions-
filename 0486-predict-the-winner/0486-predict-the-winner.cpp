class Solution {
public:
int helper(vector<int>& nums , int s , int e , vector<vector<int>>& dp){
    if(s>e)return 0;
    if(s == e)return nums[s];
    if(dp[s][e] != INT_MIN)return dp[s][e];

    int i = nums[s]- helper(nums , s+1 , e , dp);
    int j = nums[e] - helper(nums , s , e-1 , dp);

    return dp[s][e] = max(i , j);
}
    bool predictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp (n , vector<int>(n , INT_MIN));

        return helper(nums , 0 , n-1, dp)>=0 ;
    }
};