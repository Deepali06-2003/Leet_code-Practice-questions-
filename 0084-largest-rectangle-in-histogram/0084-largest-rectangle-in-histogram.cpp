class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int n = heights.size();
        int max_area=0;

        for(int i=0;i<n-1;i++){
            while(!st.empty() && heights[st.top()]>heights[i]){
                int ele = heights[st.top()];
                st.pop();

                int next_smaller =i;
                int prev_smaller = (st.empty())?-1 : st.top();

                max_area = max (max_area , (next_smaller-prev_smaller-1)* ele );
            }

            st.push(i);
        }
        while(!st.empty()){
            int ele = heights[st.top()];
            st.pop();

            int next_smaller =n;
            int prev_smaller = (st.empty())?-1 : st.top();
            max_area = max (max_area , (next_smaller-prev_smaller-1)* ele );
        }
        return max_area;
    }
};