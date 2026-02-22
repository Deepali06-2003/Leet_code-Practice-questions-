class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
        int ans = INT_MIN;
        
        for(int i=0;i<heights.size();i++){
           
            while(!st.empty() && heights[i]< heights[st.top()]){
                int ele = heights[st.top()];
                st.pop();

                int nxp = i;
                int prp = (st.empty())? -1 : st.top();

                ans = max( ans , (nxp- prp-1)* ele);
            }
            st.push(i);
        }
        while(!st.empty()){
                int ele = heights[st.top()];
                st.pop();

                int nxp = heights.size();
                int prp = (st.empty())? -1 : st.top();

                ans = max( ans , (nxp-prp-1)* ele);
            
            }
        return ans;
    }
};