class Solution {
public:
void helper(vector<int>& nums, vector<vector<int>>& res, vector<int>& curr, vector<bool>& used , int s){
    if(curr.size() == nums.size()){
        res.push_back(curr);
        return;
    }
    for(int i = 0;i<nums.size();i++){
        if(used[i])continue;

        if(i >0 && nums[i] == nums[i-1] && used[i-1] != true)continue;

        curr.push_back(nums[i]);
        used[i]= true;

        helper(nums , res , curr , used , i+1);

        curr.pop_back();
        used[i]= false;
    }

}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<vector<int>>res;
        vector<int>curr;

        int n = nums.size();
        vector<bool>used(n , false);
        sort(nums.begin() , nums.end());
        helper(nums , res , curr , used , 0);
        return res;
    }
};