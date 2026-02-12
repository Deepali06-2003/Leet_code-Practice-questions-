class Solution {
public:
    bool isPalindrome(string s) {
        int l=0, h = s.size()-1;
        transform(s.begin(), s.end(), s.begin() ,:: tolower);

        while(l<h){
            if(!isalnum(s[l])){
                l++;
                continue;
            }

            if(!isalnum(s[h])){
                h--;
                continue;
            }
            if(s[l]!= s[h])return false;

            l++;
            h--;
        }return true;
    }
};