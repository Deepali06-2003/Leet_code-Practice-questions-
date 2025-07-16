class Solution {
public:
    bool canPartition(vector<int>& nums) {
        
        int sum= 0;
        for(int i =0;i<nums.size();i++){
            sum = sum+nums[i];
        }
        if(sum%2!=0) return false;

        int n = nums.size();

        vector<vector<unsigned long long>>dp (n+1 , vector< unsigned long long>(sum/2 + 1, 0));
        for(int i=0;i<n;i++) dp[i][0] = 1;

        for(int i = 1 ;i<= n;i++){
            for(int j =0;j<= sum/2 ;j++){

                if(nums[i-1] > j){
                    dp[i][j] = dp[i-1][j];
                }
                else{
                    dp[i][j] = dp[i-1][j] + dp[i-1][j- nums[i-1]];
                }
            }
        }

        return dp[n][sum/2];


    }
};