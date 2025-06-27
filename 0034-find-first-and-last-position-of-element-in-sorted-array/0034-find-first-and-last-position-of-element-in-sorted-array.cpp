class Solution {
public:
int f_occ(vector<int>&nums , int target){
    int ans = -1;
        int l = 0;
        int h = nums.size()-1;
        while(l<=h){
            int m = (l+h)/2;
            
            if(nums[m]==target){
                ans = m;
                h = m-1;
                
            }
            else if(target >nums[m]){
                l = m+1;
            }
            else{
                h = m-1;
            }
        }
        return ans;
}
int l_occ(vector<int>&nums, int target){
    int ans = -1;
        int l = 0;
        int h = nums.size()-1;
        while(l<=h){
            int m = (l+h)/2;
            
            if(nums[m]==target){
                ans = m;
                l = m+1;
                
            }
            else if(target >nums[m]){
                l = m+1;
            }
            else{
                h = m-1;
            }
        }
        return ans;
}


    vector<int> searchRange(vector<int>& nums, int target) {
        vector <int>ans(2 , -1);
        if(nums.size()==0){
            return ans;
        }
        ans[0] = (f_occ(nums , target));
        ans[1] = (l_occ(nums , target));
        return ans;

    }
    

};