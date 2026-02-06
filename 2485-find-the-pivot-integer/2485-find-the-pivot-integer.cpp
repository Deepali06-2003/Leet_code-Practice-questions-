class Solution {
public:
    int pivotInteger(int n) {
        if(n<=0)return -1;
        if(n==1)return 1;

        int s=0;
        for(int i=1;i<=n;i++)s += i;
        
        int ls =0 , rs =s;

        for(int i =1;i<=n;i++){
            if(i==1){
                ls = 0;
                rs = s-i;
            }
            else {
                ls = ls+i-1;
                rs = rs-i;
            }

            if(ls == rs)return i;
        }return -1;
    }
};