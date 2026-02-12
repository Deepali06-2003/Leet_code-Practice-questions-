class Solution {
public:
int helper(vector<int>& nums, int pages){

    int s=1;
    long long curr_s =0;
    for(int i=0;i<nums.size();i++){

        if((curr_s+nums[i])<=pages) curr_s = curr_s+nums[i];
        else{
            s= s+1;
            curr_s = nums[i];
        }
    }
    return s;
}

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();

        if(k>n)return -1;
        long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0);

        while(low<=high){
            long long mid = (low+high)/2;

            int ans = helper(nums, mid);
            if(ans>k) low = mid+1;
            else high = mid-1;

        }return low;
    }
};