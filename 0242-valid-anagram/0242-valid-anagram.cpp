class Solution {
public:
    bool isAnagram(string s, string t) {
            int s1 = s.size();
            int t1 = t.size();

            if(s1 != t1)return false;

            unordered_map<char , int>m;

            for(char c : s){
                m[c]++;
            }

            for(char c : t){
                if(m[c]==0 || m.count(c)==0) return false;
                m[c]--;
            }

            return true;
        }
};