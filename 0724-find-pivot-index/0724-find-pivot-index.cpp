class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        
        int s =0;
        int n = nums.size();
        for(int i =0;i<n;i++)s=s+nums[i];

        int l =0 , r=0;

        for(int i = 0;i<n;i++){
            if(i==0){
                l =0;
                r = s- nums[i];
            }
            else{
                l = l+nums[i-1];
                r = r-nums[i];
            }
            if(l==r)return i;
        }
        return -1;
    }
};