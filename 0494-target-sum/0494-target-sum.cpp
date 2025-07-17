class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();

        int sum =0;
        for(int i=0;i<n ;i++){
            sum = sum+ nums[i];
        }

        if((sum+ target)%2 != 0 || sum+target< 0 ){
            return 0;
        }
        int t = (sum+ target)/2;

        vector<vector<unsigned long long>> dp(n+1 , vector<unsigned long long>(t+1 , 0));

        for(int i=0;i<= n;i++) dp[i][0] = 1;

        for(int i=1;i<= n;i++){
            for(int j = 0;j<= t ;j++){
                if(nums[i-1]>j){
                    dp[i][j]= dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i-1][j- nums[i-1]];//pull dp.
                }
            }
        }
        return dp[n][t];
    }
};