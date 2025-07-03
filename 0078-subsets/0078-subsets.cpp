class Solution {
public:
void subset(vector<int>& nums , vector<vector<int>>& res , vector<int>curr, int start ){


    res.push_back(curr);
    

    for(int i =start ; i<nums.size();i++){
        curr.push_back(nums[i]);

        subset(nums , res , curr ,i+1);
        curr.pop_back();

    }
    
}



    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int>curr;
        subset(nums , res , curr, 0);

        return res;
    }
};