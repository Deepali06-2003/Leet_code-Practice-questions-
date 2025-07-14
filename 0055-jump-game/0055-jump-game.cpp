class Solution {
public:
    bool canJump(vector<int>& nums) {
        if(nums.size()==0) return true;

        int lr = nums.size()-1;
        for(int i = nums.size()-2 ; i>=0;i--){
            if(i + nums[i]>= lr)
            lr = i;
        }
        if(lr ==0) return true;
    return false;
    }
    
};