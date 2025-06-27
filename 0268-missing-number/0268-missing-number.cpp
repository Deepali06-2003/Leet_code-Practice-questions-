class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i =0;
        int n = nums.size();
        while(i<nums.size()){

            if(nums[i]!= i && nums[i]< n){
                swap(nums[i] , nums[nums[i]]);
            }
            else{
                i++;
            }
        }
        for(int j = 0;j<n;j++){
            if(nums[j]!= j){
                return j;
            }
        }

        return n;
    }
};