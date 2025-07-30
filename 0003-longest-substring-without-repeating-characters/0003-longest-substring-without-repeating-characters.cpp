class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int max_l =0 , l=0;

        unordered_set<char>seen;

        for(int i=0;i<s.size() ;i++){
            while(seen.find(s[i]) != seen.end()){
                seen.erase(s[l]);
                l++;
            }
            seen.insert(s[i]);
            max_l = max( max_l , i-l +1);
        }return max_l;
    }
};