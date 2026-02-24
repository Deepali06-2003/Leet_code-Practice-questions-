class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        
        vector<pair<long long , pair<int, int>>>arr;

        for(auto& p : points){
            long long d = 1LL*p[0]*p[0] + 1LL*p[1]*p[1];
            arr.push_back({d, {p[0], p[1]} });
        }

        sort(arr.begin(), arr.end());

        vector<vector<int>>res;
        for(int i =0;i<k ;i++){
            res.push_back({arr[i].second.first , arr[i].second.second });
        }

        return res;
    }
};