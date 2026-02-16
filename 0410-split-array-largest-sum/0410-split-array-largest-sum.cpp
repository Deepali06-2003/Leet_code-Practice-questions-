class Solution {
public:
int helper(vector<int>& nums, int k, int m){

    int c=1, curr_s =0;

    for(int i=0;i<nums.size();i++){
        if((curr_s+nums[i])<= m){
            curr_s = curr_s+ nums[i];
        }
        else{
            c= c+1;
            curr_s = nums[i];

        }
    }
     return c;
}
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        
        long long low = *max_element(nums.begin(), nums.end());
        long long high = accumulate(nums.begin(), nums.end(), 0);

        while(low<=high){

            long long mid = (low+high)/2;

            int x = helper(nums, k , mid);
            if(x > k)low = mid+1;
            else high = mid-1;
        }

        return low;
    }
};