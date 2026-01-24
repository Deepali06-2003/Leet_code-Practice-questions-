class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> res;

        if(n<3)return res;

        sort(nums.begin(), nums.end());

        for(int i=0;i<n-2;i++){
            int target = -nums[i];

            int j =i+1, k = n-1;

            if(i>0 && nums[i]== nums[i-1]){
                continue;
            }

            while(j<k){
                if(nums[j]+nums[k] == target){

                    vector<int>curr;
                    curr.push_back(nums[i]);
                    curr.push_back(nums[j]);
                    curr.push_back(nums[k]);
                    j++;k--;
                    
                    while(j<k && nums[j]==nums[j-1])j++;
                    while(j<k && nums[k]==nums[k+1])k--;

                   res.push_back(curr);
                }
                else if(nums[j]+nums[k] > target)k--;
                else j++;

            }
            
        }
        return res;
    }
};