class Solution {
public:
    int maxArea(vector<int>& height) {
        
         int l = 0;
    int r = height.size() - 1;
    int a = 0;
        while(l<r){
            int h = min(height[l] , height[r]);
            a = max(a , h * (r-l));

            if (height[l] < height[r]) {
            l++;
             } else {
                r--;
            }
        }
         return a;
    }
};