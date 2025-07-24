class Solution {
public:
bool helper(vector<int>& weights, int days , int m){
    int c=0;
    int d=1;
    for(int i =0;i<weights.size();i++){

        if(c+ weights[i] > m){
            d++;
            c=0;
        }
        c= c+ weights[i];
    }
    return d<= days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin() , weights.end());
        int h = accumulate(weights.begin() , weights.end() , 0);

        while(l<h){
            int m = (l+h)/2;

            if(helper(weights , days , m)){
                h=m;
            }
            else{
                l = m+1;
            }
        }
        return h;
    }
};