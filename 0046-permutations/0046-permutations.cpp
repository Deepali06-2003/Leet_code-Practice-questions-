class Solution {
public:
void helper(vector<int>& nums ,vector<int>& curr,vector<vector<int>>& res , int s ){

    if(curr.size() == nums.size()){
        res.push_back(curr);
        return;
    }

    for(int i =0;i<nums.size(); i++){
        if(find(curr.begin() , curr.end(), nums[i]) != curr.end()){
            continue;
        }

        curr.push_back(nums[i]);
        helper(nums , curr , res , i+1);
        curr.pop_back();
    }
}
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int>curr;
        vector<vector<int>>res;

        helper(nums , curr , res, 0);
        return res;
    }
};