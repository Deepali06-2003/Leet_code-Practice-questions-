class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        int n = nums.size();

        vector<vector<int>>dp(n+1, vector<int>(n+1 , 0));

        for(int i=1;i<=n;i++){
            for(int j =1;j<=n;j++){
                if(i<j && nums[i-1] == nums[j-1]){
                    //dp[i][j] = max(dp[i-1][j] , dp[i][j-1])+ 1;
                    dp[i][j]=1;
                }
                
            }
        }int c=0;
        for(int i=0;i<=n;i++){
            for(int j =0;j<=n;j++){
                
                    if(dp[i][j]==1)c++;
                
            }
            cout<<endl;
        }
        return c;
    }
};