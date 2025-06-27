class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i =0;
        int n= nums.size();
        while(i<n){
            int curr_i = nums[i]-1;

            if(nums[i]!= nums[curr_i]){
                swap(nums[i], nums[curr_i]);
            }
            else i++;
        }
        vector <int>ans;
        for(int j =0;j<n ;j++){
            if(nums[j]-1 != j){
                ans.push_back(j+1);
            }
        }
        return ans;
    }
};