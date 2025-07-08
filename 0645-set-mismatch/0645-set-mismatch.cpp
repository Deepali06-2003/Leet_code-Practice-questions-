class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int i=0;
        while(i<nums.size()){
            int c = nums[i]-1;
            if(nums[i] != nums[c]){
                swap(nums[i] , nums[c]);
            }
            else{
                i++;
            }
        }
vector<int>res(2, -1);
        for(int j=0;j<nums.size();j++){
            if(nums[j]-1 != j){
                res[0]= nums[j];
                res[1]= j+1;
            }
        }
        return res;
    }
};