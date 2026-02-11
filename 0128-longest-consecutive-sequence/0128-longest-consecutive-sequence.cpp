class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int n = nums.size();
        if(n==0)return 0;
        sort(nums.begin(), nums.end());

        int longest = 1, c=0, l_smaller=INT_MIN;
        for(int i=0;i<n;i++){

            if((nums[i]-1) == l_smaller){
                l_smaller = nums[i];
                c++;
            }
            else{

                if(nums[i]!=l_smaller){
                    c=1;
                    l_smaller = nums[i];
                }
            }
            longest = max(longest, c);
        }
        return longest;
        


    }
};