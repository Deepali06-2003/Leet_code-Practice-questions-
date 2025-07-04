class Solution {
public:
void result(vector<int>&nums , vector<vector<int>>& res , vector<int>& curr , int start){

if(nums.size() == curr.size()){
    res.push_back(curr);
    return;
    
}
for(int i= 0 ;i<nums.size();i++){
    if(find(curr.begin() , curr.end() , nums[i] ) != curr.end()){
        continue;
    }
    curr.push_back(nums[i]);
    result(nums , res , curr , i+1);
    curr.pop_back();

}
}


    vector<vector<int>> permute(vector<int>& nums) {
        
        vector<vector<int>> res;
        vector<int>curr;

        result(nums, res , curr , 0);
        return res;
    }
};