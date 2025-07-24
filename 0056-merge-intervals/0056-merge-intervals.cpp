class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        vector<vector<int>> result;
        sort(intervals.begin(),intervals.end());
        //result.push_back(intervals[0]);
        int start = intervals[0][0];
        int end = intervals[0][1];
        for(int i=1; i<n; i++){
            if(intervals[i][0] <= end)end = max(end , intervals[i][1]);
            else{
                result.push_back({start , end});
                start = intervals[i][0];
                end = intervals[i][1];
            }
        }
        result.push_back({start , end});
        return result;
    }
};