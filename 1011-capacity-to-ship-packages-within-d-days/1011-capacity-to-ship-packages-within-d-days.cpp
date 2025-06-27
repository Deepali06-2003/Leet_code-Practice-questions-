class Solution {
public:
bool to_check(vector<int>&weights , int capacity, int days){
    int c_d=1;
    int x = 0;
    for(int i=0;i<weights.size();i++){
        if(x+weights[i] > capacity){
            c_d++;
            x = 0;
        }
        
        x = x + weights[i];
    }
    return c_d <= days;
}

    int shipWithinDays(vector<int>& weights, int days) {
        int n = weights.size();

        int s = 0;

        for(int i=0;i<n;i++){
            s = s+weights[i];
        }

        int l = *max_element(weights.begin() , weights.end());
        int h = s;
        int ans = -1;

        while(l<=h){
            int m =(l+h)/2;

            if(to_check(weights, m , days)){
                ans = m;
                h = m-1;

            }
            else{
                l = m+1;
            }

        }
        return ans;

        
    }
};