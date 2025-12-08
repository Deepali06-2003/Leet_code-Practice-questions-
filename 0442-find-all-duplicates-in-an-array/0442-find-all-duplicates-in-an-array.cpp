class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector<int>res;

        int n = nums.size();
        int i=0;

        while(i<n){
            int curr = nums[i]-1;

            if(nums[i]<= n && nums[i]!=nums[curr])swap(nums[i] , nums[curr]);
            else i++;
        }

        for(int j=0;j<n;j++){
            if(nums[j] != j+1){
                res.push_back(nums[j]);
            }
        }return res;
    }
};