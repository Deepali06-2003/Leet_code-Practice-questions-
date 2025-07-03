class Solution {
public:
void result(vector<int>& nums ,vector<int>&curr ,   vector<vector<int>>& res , int start ){
    res.push_back(curr);
    for(int i = start ; i<nums.size(); i++){
        curr.push_back(nums[i]);
        result(nums , curr , res , i+1);
        curr.pop_back();
    }
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int>curr;
        vector<vector<int>> res;

        result(nums , curr , res , 0);

        return res;


    }
};