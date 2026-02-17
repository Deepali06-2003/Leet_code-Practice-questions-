class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        vector<pair<long long, pair<int,int>>> v;

        for(auto &p : points) {
            long long d = 1LL*p[0]*p[0] + 1LL*p[1]*p[1];
            v.push_back({d, {p[0], p[1]}});
        }

        sort(v.begin(), v.end());

        vector<vector<int>>res;
        for(int i = 0; i < k; i++) {
            res.push_back({v[i].second.first,v[i].second.second});
        }


    return res;
    }
};