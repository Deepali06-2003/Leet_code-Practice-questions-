class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();

        int i =0;
        while(i<n){
            int curr_i = nums[i];
            if(nums[i]<n && nums[i] != nums[curr_i])swap(nums[i], nums[curr_i]);
            else i++;
        }

        for(int j=0;j<n;j++){
            if(nums[j] != j)return j;
        }return i;
    }
};