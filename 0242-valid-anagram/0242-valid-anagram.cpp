class Solution {
public:
    bool isAnagram(string s, string t) {
        
        if(s.size() != t.size())return false;

       unordered_map<char, int>map;
       for(char c: s){
        map[c]++;
       }

       for(char c:t)map[c]--;

       for(int i =0;i<map.size();i++){
        if(map[i]!=0)return false;
       }
               return true;
    }
};