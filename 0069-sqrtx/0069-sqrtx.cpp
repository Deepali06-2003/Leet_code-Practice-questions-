class Solution {
public:
    int mySqrt(int x) {
        int l = 0;
        long long h = x;
        int a= -1566666666666666;
        while(l<=h){
            int m = (l+ h)/2;
            if((long long)m * m == x){
                return m;
            }
            else if(x>(long long)m*m){
                a = m;
                l = m +1;
                
            }
            else{
                h = m-1;
            }
        }
        return a;
    }
};