class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int c=0;
        int x = nums[0];
        for(int i=0;i<nums.size();i++){
            if(c==0){
                x = nums[i];
            }
            if(nums[i]==x){
                c++;
            }
            else {
                c--;
            }
        }
        return x;
    }
};