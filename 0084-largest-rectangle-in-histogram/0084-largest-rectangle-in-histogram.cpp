class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        
        int n = heights.size();
        stack<int>st;
        int max_area =0;
        
        for(int i=0;i<n;i++){
            //encountered a smaller element then the element
            while(!st.empty() && heights[st.top()]> heights[i]){
                int ele = st.top();
                st.pop();
                
                int next_smaller = i;
                int pre_smaller = st.empty() ? -1 : st.top();

                max_area = max( max_area , heights[ele]*(next_smaller -1-pre_smaller) );
            }
            st.push(i);

        }
        while(!st.empty()){
            int ele = st.top();
            st.pop();

            int next_smaller = n;
            int pre_smaller = st.empty() ? -1 : st.top();
            max_area = max( max_area , heights[ele]*(next_smaller -1- pre_smaller) );
        }

        return max_area;
    }
};