class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n = nums.size();
        int pre=0 , suf= 0;
        int s=0;
        
        for(int i=0;i<n;i++){
            s= s+ nums[i];
        }

        for(int i=0;i<n;i++){
            if(i==0){
                pre=0;
                suf = s-nums[i];
            }
            else{
                pre = pre+ nums[i-1];
                suf = suf - nums[i];
            }
            

            if(pre== suf){
                return i;
            }

        }
        return -1;
    }
};