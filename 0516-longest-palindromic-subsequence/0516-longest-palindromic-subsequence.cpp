class Solution {
public:
    int longestPalindromeSubseq(string s) {
        
        int n1 = s.size();
        string x = s;
        reverse(s.begin(), s.end());

        vector<vector<int>>dp(n1+1, vector<int>(n1+1, 0));

        for(int i =1 ;i<= n1;i++){
            for(int j=1;j<=n1;j++){

                if(s[i-1] == x[j-1]){
                    dp[i][j]= dp[i-1][j-1]+1;
                }
                else{
                    dp[i][j]= max(dp[i-1][j] , dp[i][j-1]);
                }
            }
        }

        return dp[n1][n1];
    }
};