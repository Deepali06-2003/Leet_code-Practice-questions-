class Solution {
public:
int to_check(vector<int>& weights, int days, int m){
    int s =0 , c_d =1;

    for(int i =0;i<weights.size();i++){
        if((weights[i]+s) <= m) s = s+weights[i];
        else{
            c_d = c_d+1;
            s= weights[i];
        }
    }return days >= c_d;
}
    int shipWithinDays(vector<int>& weights, int days) {
        
        int ans = -1;
        int l = *max_element(weights.begin(), weights.end());
        int h = accumulate(weights.begin() , weights.end(),0);

        while(l<=h){
            int m = (l+h)/2;
            if(to_check(weights, days , m)){
                ans = m;
                h = m-1;
            }
            else{
                l = m+1;
            }
        }return ans;

    }
};