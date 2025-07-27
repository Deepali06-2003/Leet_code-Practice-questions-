class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l =0;
        int h = nums.size()-1;
        int ans=-1;
        while(l<=h){
            int m = (l+h)/2;
            if(nums[m] == target){
                return m;
            }
            else if(nums[m]<target){
                l = m+1;
                
            }
            else{
                h = m-1;
                ans = m;
                
            }
        }
        if(ans ==-1)
        ans = h+1;

        return ans;
    }
};