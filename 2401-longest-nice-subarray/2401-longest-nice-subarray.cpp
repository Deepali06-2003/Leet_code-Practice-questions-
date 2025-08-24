class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int num =0;
        int j =0;
        int ans =0;

        for(int i =0;i<nums.size();i++){
            while((nums[i] & num)!=0){
                num = num^nums[j++];
            }
            num = num| nums[i];
            ans = max(ans , i-j+1);
        }

        return ans;
    }
};