class Solution {
public:
    vector<int> findDisappearedNumbers(vector<int>& nums) {
        int i =0;
        int n = nums.size();
        while(i<n){
            int curr = nums[i]-1;
            if(nums[curr]!= nums[i]){
                swap(nums[i], nums[curr]);
            }
            else{
                i++;
            }
        }

        vector<int>res;

        for(int j =0; j<nums.size() ;j++){
            if(nums[j] != j+1){
                res.push_back(j+1);
            }
        }
        return res;
    }

};