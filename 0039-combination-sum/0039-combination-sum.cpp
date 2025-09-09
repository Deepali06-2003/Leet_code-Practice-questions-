class Solution {
public:
void helper(vector<int>& candidates, int target , vector<vector<int>>& res , vector<int>& curr , int ind){
    if(target == 0){
        res.push_back(curr);
        return;
    }
    if(target<0 || candidates.size() == ind)return;

    curr.push_back(candidates[ind]);
    helper(candidates , target-candidates[ind] , res , curr , ind);
    curr.pop_back();

    helper(candidates , target , res , curr, ind+1);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>curr;

        helper(candidates , target , res , curr , 0);
        return res;
    }
};