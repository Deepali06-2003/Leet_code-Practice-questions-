class Solution {
public:
    vector<int> findErrorNums(vector<int>& nums) {
        int n = nums.size();
        vector <int> ans(2, -1);

        int i=0;
        while(i<n){
            int c_i = nums[i]-1;
            if(nums[i]!= nums[c_i]){
                swap(nums[i] , nums[c_i]);
            }
            else{
                i++;
            }
        }
        for(int j=0;j<n;j++){
            if(nums[j]!= j+1){
                ans[0]= nums[j];
                ans[1] = j+1;
            }
        }
        
        return ans;
    }
};