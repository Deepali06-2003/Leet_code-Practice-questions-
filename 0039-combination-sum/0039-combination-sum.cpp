class Solution {
public:
void helper(vector<int>& candidates , int target , vector<vector<int>>& res , vector<int>& curr , int s){
    if(target ==0){
        res.push_back(curr);
        return;
    }
    if (s == candidates.size() || target < 0) return;
    
        curr.push_back(candidates[s]);
        helper(candidates , target- candidates[s], res , curr , s);
        curr.pop_back();
    
    
    helper(candidates , target, res , curr , s+1);
}
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        vector<vector<int>>res;
        vector<int>curr;

        helper(candidates , target , res , curr , 0);
        return res;
    }
};