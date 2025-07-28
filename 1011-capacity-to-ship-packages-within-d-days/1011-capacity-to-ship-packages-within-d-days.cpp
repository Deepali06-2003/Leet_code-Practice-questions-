class Solution {
public:
bool helper(vector<int>& weights, int days , int m){
    int d=1  , c =0;
    for(int i =0;i<weights.size();i++){
        if(c+ weights[i] > m){
            c=0;
            d++;
        }
        c = c+ weights[i];
    }
    return d<= days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin() , weights.end());
        int h = accumulate(weights.begin() , weights.end() , 0);

        while(l<h){
            int m = (l+h)/2;

            if(helper(weights , days , m)){
                h = m;
            }
            else{
                l = m+1;
            }
        }
        return h;
    }
};