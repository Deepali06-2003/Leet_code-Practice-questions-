class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        vector <int>ans;
        int n = nums.size()-1;
        int i = 0;
        while(i<=n){
            int c = nums[i]-1;
            if(nums[c]!= nums[i]){
                swap(nums[i], nums[c]);
            }
            else i++;
        }

        for(int j=0;j<=n;j++){
            if(nums[j]-1 != j){
                ans.push_back(nums[j]);
            }
        }
        return ans;
    }
};