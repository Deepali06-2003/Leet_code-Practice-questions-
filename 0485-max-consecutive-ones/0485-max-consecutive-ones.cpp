class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_1 = 0;
        int count =0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==1){
                count++;
            }
            else{
                max_1 = max(count , max_1);
                count =0;
            }
        }
        max_1 = max(count , max_1);
        return max_1;
    }
};