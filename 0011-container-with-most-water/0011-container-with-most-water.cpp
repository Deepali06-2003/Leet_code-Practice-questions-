class Solution {
public:
    int maxArea(vector<int>& height) {
        
        int l = 0;
        int r = height.size()-1;

        int max_area = 0;

        while(l<r){
            int length = min(height[l], height[r]);
            int breath = r - l;

            int area = length * breath;
            max_area = max(area , max_area);

            if(height[l]<height[r])l++;
            else r--;
        }return max_area;

        
     
    }
};