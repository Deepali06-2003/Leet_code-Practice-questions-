class Solution {
public:
    long long maxPower(vector<int>& stations, int r, int k) {
        int n = stations.size();
        vector<long long> pref(n + 1, 0);

        for (int i = 0; i < n; i++)
            pref[i + 1] = pref[i] + stations[i];

        auto can = [&](long long x) {
            vector<long long> added(n + 1, 0);
            long long used = 0, window = 0;

            for (int i = 0; i < n; i++) {
                window += added[i];

                int left = max(0, i - r);
                int right = min(n - 1, i + r);
                long long curr = pref[right + 1] - pref[left] + window;

                if (curr < x) {
                    long long need = x - curr;
                    used += need;
                    if (used > k) return false;

                    window += need;
                    if (i + 2 * r + 1 < n)
                        added[i + 2 * r + 1] -= need;
                }
            }
            return true;
        };

        long long low = 0, high = 1e18, ans = 0;
        while (low <= high) {
            long long mid = (low + high) / 2;
            if (can(mid)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
