class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices[0];

        int p =0;

        for(int i =1 ;i <prices.size() ;i++){

            m = min(prices[i], m);
            
            int x = prices[i] - m;
            p = max(p, x);

        }
        return p;
    }
};