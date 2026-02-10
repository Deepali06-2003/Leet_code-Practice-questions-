class Solution {
public:
    vector<int> sortArrayByParity(vector<int>& nums) {
        int h= nums.size()-1;
        int i=0;
        while(i<h){
            if(nums[i]%2!=0){
                swap(nums[i], nums[h]);
                h--;
            }
            else{
                i++;
            }
        }
        return nums;
    }
};