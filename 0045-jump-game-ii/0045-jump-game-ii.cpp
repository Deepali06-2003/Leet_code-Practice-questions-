class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        
        int jump = 0, farthest = 0, stop ;

        for(int i=0;i<n-1;i++){
            farthest = max(farthest , nums[i]+i);

            if(i== stop){
                jump++;
                stop = farthest;
            }
        }
        return jump;

    }
};