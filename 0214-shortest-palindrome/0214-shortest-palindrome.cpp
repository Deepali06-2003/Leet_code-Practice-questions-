class Solution {
public:
    string shortestPalindrome(string s) {
        int n = s.size();
        string x = s;
        reverse(s.begin(), s.end());

        for(int i =0;i<s.size();i++){
            if(memcmp(x.c_str() , s.c_str()+i,n-i) == 0){
                return  s.substr(0, i)+x;
            }
        }
        return s + x;
    }
};