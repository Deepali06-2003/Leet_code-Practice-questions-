class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int ans =0;

        int n = prices.size();
        for(int i =1;i<n;i++){
            int p = prices[i]-prices[i-1];
            if(p>0)ans = ans+p;
        }return ans;
    }
};