class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size(), ans = 0;

        for (int k = n - 1; k >= 2; k--) {
            int i = 0, j = k - 1;
            while (i < j) {
                if (nums[i] + nums[j] > nums[k]) {
                    ans += (j - i);  // all i..j-1 form valid triangles with j,k
                    j--;
                } else {
                    i++;
                }
            }
        }
        return ans;
    }
};