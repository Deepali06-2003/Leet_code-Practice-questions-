class Solution {
public:
int helper(vector<int>& weights, int days, int m){
    int curr_sum=0;
    int d=1;
    for(int i=0;i<weights.size();i++){
        if((weights[i]+curr_sum) <= m)curr_sum += weights[i];
        else{
            curr_sum=weights[i];
            d++;
        }
    }return d<=days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin(), weights.end());
        int h = accumulate(weights.begin(), weights.end(),0);

        int ans=-1;

        while(l<=h){
            int m = (l+h)/2;

            if(helper(weights, days , m)){
                ans = m;
                h = m-1;
            }
            else{
                l=m+1;
            }
        }return ans;
    }
};