class Solution {
public:
void helper(vector<int>& nums ,vector<int>& curr , vector<vector<int>>& res , int s, vector<bool>& used ){
    if(curr.size() == nums.size()){
        res.push_back(curr);
        return;
    }

    for(int i = 0;i<nums.size();i++){
        if (used[i]) continue;
            // skip duplicates: only use the first occurrence of duplicate numbers in this position
        if (i > 0 && nums[i] == nums[i-1] && !used[i-1]) continue;

        
        used[i] = true;
        curr.push_back(nums[i]);
        helper(nums , curr , res , i+1 , used);
        curr.pop_back();

        used[i] = false;
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int>curr;
        vector<vector<int>>res;

        sort(nums.begin() , nums.end());

        vector<bool>used(nums.size() , false);
        helper(nums , curr, res , 0 , used);
        return res;
    }
};