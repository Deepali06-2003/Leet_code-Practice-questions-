class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        
        int min_sum =0;
        int sum =0;

        for(int i =0;i<n;i++){
            sum = sum + nums[i];

            min_sum = min(sum, min_sum);
        }
        return 1- min_sum;
    }
};