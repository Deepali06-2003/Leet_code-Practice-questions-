class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        
        stack<int>s;
        vector<int>ans(temperatures.size() , 0);

     
        for(int i=0;i< temperatures.size();i++){

            while(!s.empty() && temperatures[i]> temperatures[s.top()]){
                int x= s.top();
                s.pop();
                ans[x] = i-x;
            }
            s.push(i);
        }
        return ans;
    }
};