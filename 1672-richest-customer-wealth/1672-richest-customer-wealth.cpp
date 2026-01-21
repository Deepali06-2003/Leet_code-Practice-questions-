class Solution {
public:
    int maximumWealth(vector<vector<int>>& accounts) {
        int ans =-1;
        int n = accounts.size();
        int m = accounts[0].size();

        for(int i =0;i<n;i++){
            int c_sum =0;
            for(int j =0;j<m;j++){
                c_sum = c_sum+ accounts[i][j];
            }
            ans = max(ans, c_sum);
        }

        return ans;
    }
};