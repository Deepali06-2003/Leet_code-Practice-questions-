class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        if(n==1)return nums[0];

        vector<int>arr(n , 0);
        vector<int>arr2(n,0);
        arr[0] = nums[0];
        arr[1] = max(nums[0] , nums[1]);

        for(int i=2 ;i<n;i++){
            
            arr[i] = max( arr[i-1] , arr[i-2] + nums[i]);
        }
        arr2[0]=0;
        arr2[1]= nums[1];
        for(int i=2;i<n;i++){
            if(i== (n-1))arr[i]= arr[i-1];
            arr2[i]= max(arr2[i-1] , arr2[i-2]+nums[i]);
        }

        return max(arr.back() , arr2.back());
    }
};