class Solution {
public:
    int mySqrt(int x) {
        int ans =0;
        int l =0;
        int h = x;

        while(l<= h){
            int m = (l+h)/2;

            if((unsigned long long)m*m == x)return m;

            else if( (unsigned long long )m*m < x){
                ans = m;
                l = m+1;
            }
            else{
                h = m-1;
            }
        }return ans;
    }
};