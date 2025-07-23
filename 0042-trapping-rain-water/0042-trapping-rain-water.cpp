class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int>left_max(n, 0);
        vector<int>right_min(n , 0);

        left_max[0] = height[0];
        for(int i=1;i<n;i++){
            left_max[i] = max(height[i] , left_max[i-1]);
        }

        right_min[n-1] = height[n-1];
        for(int i = n-2;i>=0;i--){
            right_min[i] = max(height[i] , right_min[i+1]);
        }
        int water =0;
        for(int i =1;i<n;i++){
            water = water+ (min(left_max[i], right_min[i])-height[i]);
        }

        return water;
    }
};