class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        vector<int>dp1(n, 0);

        dp1[0] = cost[0];
        dp1[1] = cost[1];

        for(int i =2;i<n;i++){
            dp1[i] = cost[i]+ min(dp1[i-2] , dp1[i-1]);
        }

        return min(dp1[n-2] , dp1[n-1]);
    }
};