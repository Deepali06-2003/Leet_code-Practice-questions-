class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int l = 0;
        int h = nums.size()-1;
        int ans =0;
        while(l<=h){
            int m = (l+h)/2;
            if(nums[m] == target)return m;

            else if(nums[m] < target){
                ans = m+1;
               l = m+1;
               
            }
            else{
                
                h=m-1;
            }
        }
        return ans;
    }
};