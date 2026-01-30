class Solution {
public:
    bool isPerfectSquare(int num) {
        if(num<0)return false;
        if(num==0 || num==1)return true;

        int l =0, h=num/2;

        while(l<=h){
            int m = (l+h)/2;

            if((long long)m*m==num)return true;
            else if((long long)m*m<num)l=m+1;
            else h = m-1;
        }return false;
    }
};