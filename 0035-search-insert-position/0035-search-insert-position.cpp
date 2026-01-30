class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        
        int n = nums.size();

        int l =0;
        int h = n-1;
        int ans=-1;
        while(l<=h){
            int m = (l+h)/2;

            if(nums[m]==target)return m;

            else if(nums[m]>target){
                ans = m;
                h = m-1;
            }
            else l= m+1;
        }
        if(ans ==-1)return n;
        return ans;
    }
};