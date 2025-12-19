class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int p =1, s=1;
        int n = nums.size();
        vector<int>dp(n, 1);
        for(int i =0;i<n;i++){
            dp[i] = p;
            p = p*nums[i];
        }
        for(int i = n-1 ;i>=0 ;i--){
            dp[i] = dp[i]*s;
            s= s*nums[i];

        }return dp;
    }
};