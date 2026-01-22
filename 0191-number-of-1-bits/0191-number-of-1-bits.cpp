class Solution {
public:
    int hammingWeight(int n) {
        if(n<=0)return -1;
        
        int c=0;
        while(n!=0){
             n = n&(n-1);
             c++;
        }return c;
    }
};