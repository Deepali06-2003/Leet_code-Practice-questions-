class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        
        int pre_sum =0;
        int sum =0;

        for(int i =0;i<n;i++){
            sum = sum + nums[i];

            pre_sum = min(sum, pre_sum);
        }
        return 1- pre_sum;
    }
};