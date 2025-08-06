class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {

        if(nums.size()==0 || nums.size()==1)return nums.size();

        vector<int>res;
        res.push_back(nums[0]);

        for(int i =0;i<nums.size();i++){
            if(res.back() < nums[i]){
                res.push_back(nums[i]);
            }
            else{
                int ind = lower_bound(res.begin(), res.end() , nums[i]) - res.begin();
                res[ind] = nums[i];
            }
        }
        return res.size();

    }
};