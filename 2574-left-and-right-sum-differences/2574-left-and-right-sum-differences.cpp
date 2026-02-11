class Solution {
public:
    vector<int> leftRightDifference(vector<int>& nums) {
        
        int n = nums.size();
        vector<int>res(n, 0);
        
       int s=0;
       for(int i :nums)s=s+i;
       int ls=0 , rs=0;

       for(int i=0;i<nums.size();i++){
        rs = s -(nums[i]+ls);
       
        res[i]= abs(ls-rs);
         ls = ls+ nums[i];
       }
        

        
        return res;
    }
};