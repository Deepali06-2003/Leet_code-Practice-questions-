class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int ls=0;
        int rs=0;
        int s=0;
        for(int i=0;i<nums.size();i++)s= s+ nums[i];

        int n = nums.size();
        for(int i =0;i<n;i++){
            if(i==0){
                ls=0;
                rs= s- nums[0];
            }
            else{
                ls = ls+ nums[i-1];
                rs= rs- nums[i];
            }

            if(ls == rs)return i;
        }
        return -1;
    }
};