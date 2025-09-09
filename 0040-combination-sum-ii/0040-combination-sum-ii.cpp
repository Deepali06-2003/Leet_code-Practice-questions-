class Solution {
public:

void helper(vector<int>& candidates, int target , vector<vector<int>>& res , vector<int>& curr , int s){
    if(target == 0){
        res.push_back(curr);
        return;
    }
    if(target<0 || candidates.size() == s)return;

    for(int i = s;i<candidates.size();i++){

        if(candidates[i] > target)break;
        if(i >s && candidates[i]== candidates[i-1])continue;
        curr.push_back(candidates[i]);
        helper(candidates , target- candidates[i] , res , curr , i+1);
        curr.pop_back();
    }
}
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<vector<int>>res;
        vector<int>curr;

        sort(candidates.begin() , candidates.end());

        helper(candidates , target , res , curr , 0);
        return res;
    }
};