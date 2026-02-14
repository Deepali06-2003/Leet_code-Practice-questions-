class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n = position.size();

        vector<pair<int, int>>arr;

        for(int i=0;i<n;i++){
            arr.push_back({ position[i], speed[i] });
        }

        sort(arr.rbegin(), arr.rend());

        double ans = (double)(target  - arr[0].first)/arr[0].second;
        int c=1;

        for(int i=1;i<n;i++){
            double curr = (double)(target - arr[i].first)/arr[i].second;
            
            if(curr > ans){
                c++;
                ans = curr;
            }
        } return c;
    }
};