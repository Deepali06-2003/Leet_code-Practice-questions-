class Solution {
public:
    int mySqrt(int x) {

        int l =0;
        int h = x;

        int ans = 0;
        while(l<=h){
            int m = (l+h)/2;
            if((long long unsigned)m*m == x)return m;
            else if((long long unsigned)m*m < x){
                ans = m;
                l= m+1;
            }
            else{
                h = m-1;
            }
        }
        return ans;
        
    }
};