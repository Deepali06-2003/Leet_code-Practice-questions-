class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        int i =0;
        while(i<n){
            int curr_i = nums[i]-1;
            if(nums[i]!= nums[curr_i]){
                swap(nums[i] , nums[curr_i]);
            }
            else{
                i++;
            }
        }
        int ans;
        for(int j=0;j<n;j++){
            if(nums[j]-1!= j){
                ans=  nums[j];
            }
        }
        return ans;
    }
};