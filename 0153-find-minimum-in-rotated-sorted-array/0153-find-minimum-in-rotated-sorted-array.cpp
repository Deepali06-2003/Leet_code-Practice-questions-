class Solution {
public:
    int findMin(vector<int>& nums) {
        int l = 0;
        int h = nums.size()-1;
        

        while(l<h){
            int m = (l+h)/2;
            //left is sorted
            if(nums[m]>nums[h]){
                //we will go to right
                l = m+1;

            }
            else{
                h = m;
            }


        }
        return nums[h];
    }
};