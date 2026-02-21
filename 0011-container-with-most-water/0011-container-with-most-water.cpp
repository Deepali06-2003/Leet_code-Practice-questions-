class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, h= n-1;
        int ans = 0;
        while(l<h){

            int len = min(height[l], height[h]);
            int bre = h-l;

            ans = max(ans , len*bre);

            if(height[l]<= height[h]) l++;
            else h--;
        }
        return ans;
    }
};