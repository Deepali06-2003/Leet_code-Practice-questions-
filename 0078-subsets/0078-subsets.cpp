class Solution {
public:

void helper(vector<int>& nums, vector<vector<int>>& res, int i, vector<int> curr){
    res.push_back(curr);

    for(int j = i;j<nums.size();j++){
        curr.push_back(nums[j]);
        helper(nums, res, j+1, curr);
        curr.pop_back();
    }
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>curr;

        helper(nums, res , 0, curr);
        return res;
    }
};