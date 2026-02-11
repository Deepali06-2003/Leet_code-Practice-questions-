class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n = nums.size();

        int s=0;
        for(int i =0;i<n;i++){
            s = s+ nums[i];
        }

        int ls=0, rs=0;
        for(int i=0;i<nums.size();i++){
            rs = s-(ls+nums[i]);
            if(rs==ls)return i;
            ls = ls+nums[i];
        }return -1;
    }
};