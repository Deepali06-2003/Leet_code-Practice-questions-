class Solution {
public:
    bool canJump(vector<int>& nums) {
        int lr = nums.size()-1;

        for(int i = nums.size()-2 ; i>=0 ;i--){
            if(lr <= nums[i]+i){
                lr = i;
            }
        }
        if(lr==0)return true;
        return false;
    }
};