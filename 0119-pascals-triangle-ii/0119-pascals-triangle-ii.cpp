class Solution {
public:
    vector<int> getRow(int rowIndex) {
        int n = rowIndex;
        vector<int>res;

        vector<vector<int>>dp(n+1, vector<int>(n+1, 0));
        for(int i =0;i<=n;i++)dp[i][0]=1;
        
        for(int i=1;i<=n;i++){
            for(int j=1;j<=n;j++){
                if(i==j)dp[i][j]=1;
                else dp[i][j]= dp[i-1][j]+ dp[i-1][j-1];
            }
        }
        
            for(int j=0;j<=n;j++){
                res.push_back(dp[n][j]);
            }
        
        
        return res;
    }
};