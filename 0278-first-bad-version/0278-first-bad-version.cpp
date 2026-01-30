// The API isBadVersion is defined for you.
// bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int l =1 , h =n;
        int ans= n;
        while(l<=h){
            int m = (l+h)/2;
            
            if(isBadVersion(m)){
                ans =m;
                h=m-1;
            }
            else{
                l = m+1;
            }
        }return ans;
    }
};