class Solution {
public:
int f_occ(vector<int>& nums, int target){
    int l = 0;
    int h = nums.size()-1;
    int ans=-1;
    while(l<=h){
        int m = (l+h)/2;

        if(nums[m] == target){
            ans = m;
            h = m-1;
        }
        else if(nums[m]<target){
            l=m+1;
        }
        else{
            h = m-1;
        }
    }
    return ans;
}

int l_occ(vector<int>& nums, int target){
    int l = 0;
    int h = nums.size()-1;
    int ans=-1;
    while(l<=h){
        int m = (l+h)/2;

        if(nums[m] == target){
            ans = m;
            l = m+1;
        }
        else if(nums[m]<target){
            l=m+1;
        }
        else{
            h = m-1;
        }
    }
    return ans;
}

    vector<int> searchRange(vector<int>& nums, int target) {
        
        vector<int> res(2);
        int x1= f_occ(nums , target);
        int x2 = l_occ(nums, target);
        res[0] = x1;
        res[1] = x2;
        return res;
    }
};