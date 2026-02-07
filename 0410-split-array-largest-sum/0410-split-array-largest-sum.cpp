class Solution {
public:

bool canSplit(vector<int>& nums, int k, long long cap) {
        long long cur = 0;
        int parts = 1;

        for (int x : nums) {
            if (x > cap) return false;

            if (cur + x > cap) {
                parts++;
                cur = x;
            } else {
                cur += x;
            }
        }
        return parts <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        long long lo = 0, hi = 0;

        for (int x : nums) {
            lo = max(lo, (long long)x);
            hi += x;
        }

        long long ans = hi;
        while (lo <= hi) {
            long long mid = lo + (hi - lo) / 2;
            if (canSplit(nums, k, mid)) {
                ans = mid;
                hi = mid - 1;
            } else {
                lo = mid + 1;
            }
        }
        return ans;
    }
};