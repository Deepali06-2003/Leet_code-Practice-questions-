class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
        int ans = INT_MIN, s=0;
        for(int i=0;i<nums.size();i++){
            s= s+nums[i];

            if(s>ans)ans = max(ans, s);
            if(s<=0)s=0;
        }
        return ans;
    }
};