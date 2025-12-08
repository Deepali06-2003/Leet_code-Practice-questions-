class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i =0;

        while(i<n){
            int curr = nums[i]-1;
            if(nums[curr]!= nums[i])swap(nums[curr], nums[i]);
            else i++;
        }

        for(int j =0;j<n;j++){
            if(nums[j] != j+1)return nums[j];
        }return -1;
    }
};