class Solution {
public:
int f_occ(vector<int>& nums, int target){
    int n = nums.size();
    int ans =-1;

    int l =0;
    int h = n-1;

    while(l<=h){
        int m = (l+h)/2;

        if(nums[m] == target){
            ans =m;
            h = m-1;
        }
        else if(nums[m]> target)h = m-1;
        else l = m+1;
    }return ans;
}

int l_occ(vector<int>& nums, int target){
    int n = nums.size();
    int ans =-1;

    int l =0;
    int h = n-1;

    while(l<=h){
        int m = (l+h)/2;

        if(nums[m] == target){
            ans =m;
            l = m+1;
        }
        else if(nums[m]> target)h = m-1;
        else l = m+1;
    }return ans;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>ans(2, -1);

        ans[0] = f_occ(nums, target);
        ans[1] = l_occ(nums, target);

        return ans;
    }
};