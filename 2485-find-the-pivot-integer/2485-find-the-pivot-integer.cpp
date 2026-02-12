class Solution {
public:
    int pivotInteger(int n) {
        int s=0;
        for(int i =1; i<=n;i++) s= s+i;

        int ls=0, rs=0;
        for(int i=1;i<=n;i++){
            rs = s- (ls+i);
            if(rs==ls)return i;
            ls= ls+i;
        }
        return -1;
    }
};