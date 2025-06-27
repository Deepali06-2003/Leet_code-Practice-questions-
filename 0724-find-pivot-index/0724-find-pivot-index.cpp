class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        
        int s=0;
        for(int i=0;i<n;i++){
            s = s+nums[i];
        }
        int s_r=0;;
        int s_l=0;
        for(int i =0;i<n;i++){
            if(i==0){
                s_l =0;
                s_r = s-nums[0];
            }
            else{
            s_l = s_l +nums[i-1];
            s_r = s_r - nums[i];
            }
            if(s_l == s_r){
                return i;
            }

        }
        return -1;
    }
};