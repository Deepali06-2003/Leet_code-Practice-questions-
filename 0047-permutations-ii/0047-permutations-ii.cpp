class Solution {
public:
void helper(vector<int>& nums ,vector<vector<int>>& res ,vector<int>& curr , vector<int>& used, int s){

    if(curr.size() == nums.size()){
        res.push_back(curr);
        return;
    }
    for(int i = 0;i<nums.size();i++){
        if(used[i])continue;
        if(i>0 && nums[i] == nums[i-1] && used[i-1])continue;

        curr.push_back(nums[i]);
        used[i]=1;

        helper(nums , res , curr , used , i+1);

        curr.pop_back();
        used[i] = 0;
    }
}
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
sort(nums.begin() , nums.end());
      vector<vector<int>>res;
      vector<int>curr;
      vector<int>used(n , 0);  

        helper(nums , res , curr , used , 0);
      return res;
    }
};