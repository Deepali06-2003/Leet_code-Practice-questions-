class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mi = prices[0];

        int p =0;

        for(int i =1;i<prices.size();i++){
            mi = min(prices[i] , mi);

            if(prices[i]- mi > p) 
                p = prices[i]- mi ;
            
            if(p<0) 
                p=0;
        }
        return p;
    }
};