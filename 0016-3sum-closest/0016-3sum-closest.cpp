class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        
        int n = nums.size();
        sort(nums.begin(), nums.end());

        int ans = nums[0]+ nums[1]+nums[2];

        for(int i=0;i<n-2 ;i++){

            int j = i+1 , k= n-1;
            while(j<k){

                long long s = (long long)nums[i] + nums[j] + nums[k];

                if(s == target)return s;
                if( abs(s-target) < abs(ans-target)){
                    ans = s;
                }
                
                if(s > target)k--;
                else j++;
            }
        }

        return ans;
    }
};