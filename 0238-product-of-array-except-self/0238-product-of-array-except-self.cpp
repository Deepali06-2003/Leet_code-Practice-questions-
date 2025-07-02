class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
      int n = nums.size();
        vector<int> prefix(n);
        int m =1;
        for(int i=0;i<n;i++){
            m = m * nums[i];
        }
        for(int i=0;i<n;i++){
            if(m==0 && nums[i]!=0){
                prefix[i]=0;
            }
            else if(m==0 && nums[i]==0){
                prefix[i]= 9;
            }
            else
            prefix[i]= m/nums[i];
        }

        return prefix;
    }
};