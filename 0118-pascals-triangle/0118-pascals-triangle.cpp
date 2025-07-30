class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>>dp(numRows, vector<int>(numRows , 0));
        vector<vector<int>>res;
        vector<int>curr;

        for(int i =0;i<numRows ;i++){
            dp[i][0]=1;
        }
        curr.push_back(dp[0][0]);
        res.push_back(curr);
        for(int i =1;i<numRows ;i++){
            curr.clear();
            curr.push_back(dp[i][0]);

            for(int j =1;j<=i ;j++){
                //curr.push_back(dp[i][0]);
                dp[i][j] = dp[i-1][j-1]+ dp[i-1][j];
                curr.push_back(dp[i][j]);
            }

            res.push_back(curr);
        }

        return res;
    }
};