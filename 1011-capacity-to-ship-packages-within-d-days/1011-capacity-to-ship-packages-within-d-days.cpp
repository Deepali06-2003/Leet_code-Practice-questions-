class Solution {
public:
bool NoOfDays(vector<int> weights, int days , int m){
    int day = 1;
    int curr=0;
    for(int i =0;i<weights.size();i++){
        //curr += weights[i];
        if(curr + weights[i] > m){
            day ++;
            curr=0;
        }
        
        curr += weights[i];
    }
    return day <=days;
}
    int shipWithinDays(vector<int>& weights, int days) {
        int l = *max_element(weights.begin() , weights.end());
        int h = accumulate(weights.begin() , weights.end() , 0);

        while(l<h){
            int m = (l+h)/2;

            if(NoOfDays(weights , days , m)){
                h = m;
            }
            else{
                l = m+1;
            }
        }
        return h;
    }
};