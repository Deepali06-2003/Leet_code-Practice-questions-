class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0;
        int l =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                l++;
            }
            else {
               if(l>max){
                max = l;
               }
                l=0;
            }
            
        }
        if(l>max){
                max = l;
            }
        return max;
    }
};