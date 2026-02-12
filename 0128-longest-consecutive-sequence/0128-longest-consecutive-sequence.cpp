class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size();
        if(n<=0)return 0;
        unordered_set<int>st;

        for(int i : nums)st.insert(i);
        int longest = 1;
        
        for(auto i: st){

            if(st.find(i-1) == st.end()){
                int c=1;
                int x = i;
                while(st.find(x+1) != st.end()){
                    c++;
                    x = x+1;
                }
                longest = max(longest , c);
            }

        }return longest;
    }
};