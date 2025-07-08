class Solution {
public:
int f_occ(vector<int> nums , int t){
    int l =0;
    int h = nums.size()-1;
    int ans=-1;
    while(l<=h){
        int m = (l+h)/2;

        if(nums[m] == t){
            ans = m;
            h = m-1;
        }
        else if(nums[m]> t){
            h = m-1;
        }
        else{
            l = m+1;
        }
    }
    return ans;
}

int l_occ(vector<int> nums , int t){
    int l =0;
    int h = nums.size()-1;
    int ans=-1;
    while(l<=h){
        int m = (l+h)/2;

        if(nums[m] == t){
            ans = m;
            l = m+1;
        }
        else if(nums[m]> t){
            h = m-1;
        }
        else{
            l = m+1;
        }
    }
    return ans;
}
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int> res(2 , -1);
        res[0]= f_occ(nums , target);
        res[1]= l_occ(nums , target);
        return res;
    }
};