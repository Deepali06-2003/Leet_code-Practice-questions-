class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int i = 0;
        while(i < nums.size()){

            int c = nums[i]-1;

            if(i<nums.size() && nums[i] != nums[c]){
                swap(nums[i], nums[c]);
            }
            else{
                i++;
            }
        }

        vector<int>res;
        for(int j=0;j<nums.size() ;j++){
            if(nums[j] != j+1){
                res.push_back(nums[j]);
                res.push_back(j+1);
                return res;
            }
        }
        return res;
    }
};