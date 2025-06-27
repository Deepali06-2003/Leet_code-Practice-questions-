class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector <int>ans;
        int n = nums.size();
        int i = 0;
        while(i<n){
            int curr_i = nums[i]-1;
            if(nums[i]!= nums[curr_i]){
                swap(nums[i] , nums[curr_i]);
            }
            else{
                i++;
            }
        }
        for(int j=0;j<n ;j++){
            if(nums[j]-1 != j){
                ans.push_back(nums[j]);
            }
        }

        return ans;

    }
};