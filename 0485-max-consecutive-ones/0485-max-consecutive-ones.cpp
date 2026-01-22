class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max_ones = 0, c=0;
        int n = nums.size();

        for(int i =0;i<n;i++){
            if(nums[i]==1)c++;
            else{
                max_ones = max(max_ones,c);
                c=0;
            }
        }max_ones = max(max_ones,c);
        return max_ones;
    }
};