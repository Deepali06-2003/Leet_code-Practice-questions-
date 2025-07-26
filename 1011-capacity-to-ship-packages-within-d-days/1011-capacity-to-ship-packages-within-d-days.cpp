class Solution {
public:
bool helper(vector<int>& weights, int days, int m ){
    int c =1;
    int curr=0;
    for(int i =0;i<weights.size() ;i++){
        if(curr+ weights[i] >m){
            c++;
            curr=0;
        }
        curr += weights[i];
    }
    return c<= days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin() , weights.end());
        int h = accumulate(weights.begin() , weights.end() , 0);

        while(l<h){

            int m = (l+h)/2;

            if(helper(weights , days , m)) h = m;

            else{
                l = m+1;
            }
        }

        return h;
    }
};