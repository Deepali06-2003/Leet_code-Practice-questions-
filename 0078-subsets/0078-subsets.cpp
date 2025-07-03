class Solution {
public:
void subset(vector<int>& nums , vector<vector<int>>& res , int index ,vector<int>& curr_r ){
    if(index <0){
        res.push_back(curr_r);
        return ;
    }
    //exclude
    subset(nums , res , index-1, curr_r);
    //include
    curr_r.push_back(nums[index]);
    subset(nums , res , index-1 , curr_r);
    curr_r.pop_back();
}
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>curr;
        subset(nums , res , nums.size()-1 , curr);

        return res;
    }
};