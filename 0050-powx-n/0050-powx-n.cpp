class Solution {
public:
double helper(double x,long long n){
    if(n==0)return 1.0;
    if(n==1)return x;

    double half = helper(x , n/2);
    if(n%2==0)return half*half;
    return half*half*x;
}
    double myPow(double x, int n) {
        long long N = n;
        if(n==0)return 1.0;
        if(n==1)return x;

        if(N<0){
            N= -N;
            x = 1.0/x;
            return helper(x , N);
        }
        
            return helper(x, N);
        
    }
};