class Solution {
public:
    int numIdenticalPairs(vector<int>& nums) {
        
        int n = nums.size();

        int c=0 , j =1;
        while(j<n){
            for(int i =0 ;i<j;i++){
                if(nums[i] == nums[j])c++;
            }
            j++;
        }return c;
    }
};