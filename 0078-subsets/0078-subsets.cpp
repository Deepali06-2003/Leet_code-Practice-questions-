class Solution {
public:
void helper(vector<int>& nums, vector<vector<int>>& res , vector<int>& curr , int s){
    res.push_back(curr);
    for(int i =s;i<nums.size();i++){
        curr.push_back(nums[i]);
        helper(nums , res , curr , i+1);
        curr.pop_back();
    }
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>curr;
        vector<vector<int>> res;

        helper(nums , res , curr , 0);
        return res;
    }
};