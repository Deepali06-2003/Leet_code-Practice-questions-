class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int i =0;
        while(i<nums.size()){
            int c = nums[i];
            if(nums[i]<nums.size() && nums[i] != nums[c]){
                swap(nums[i], nums[c]);
                
            }
            else i++;
        }

        for(int j =0;j< nums.size() ;j++){
            if(j!= nums[j]){
                return j;
            }
        }
        return i;
    }
};