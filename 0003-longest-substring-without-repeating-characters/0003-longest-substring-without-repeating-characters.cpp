class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_length =0;
        int left =0;

        unordered_set<char>seen;
        for(int r= 0 ;r<s.size() ;r++){
           
            while(seen.find(s[r]) != seen.end()){
                seen.erase(s[left]);
                left++;
            }
            seen.insert(s[r]);
            max_length = max(max_length , r-left+1);
        }

        return max_length;
    }
};