class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();

        int l=0, h=n-1;
        int area =0;
        while(l<h){

            int a = min(height[l], height[h]);
            int b = h-l;
            area = max(area, a*b);

            if(height[l]>= height[h])h--;
            else l++;
        }return area;
    }
};