class Solution {
public:
    bool isAnagram(string s, string t) {
            unordered_map <char, int> map;
            if(s.size() != t.size()){
                return false;
            }
            for(char c : s){
                map[c]++;
            }
            for(char c : t){
                if(map.count(c)==0 || map[c]==0){
                    return false;
                }
                map[c]--;
            }
    
            return true;
        }
};