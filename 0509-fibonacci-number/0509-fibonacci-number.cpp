class Solution {
public:
    int fib(int n) {
        if(n<=0)return 0;
        if(n==1)return 1;
        
        int p2 = 0;
        int p1 = 1;
        int c;
        for(int i =2 ;i<=n;i++){
            c = p1 +p2;
            p2 = p1;
            p1 = c;
        }
        return c;
    }
};