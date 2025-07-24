class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int m = prices[0];
        int p = 0;
        for(int i =1;i<prices.size();i++){
            if(m > prices[i]) m = prices[i];
            int x = prices[i]- m;

            if(x>p) p = x;
            if(x<0) p =0;
        }
        return p;
    }
};