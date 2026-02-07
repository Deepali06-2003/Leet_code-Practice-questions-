class Solution {
public:

void toLower(string &s) {
    //transform(s.begin(), s.end(), s.begin(),[](unsigned char c){ return tolower(c); });
    for(char c: s){
        if(c>= 'A' && c<='Z') c = tolower(c);
    }
}
    bool isPalindrome(string s) {
        int l =0 , h = s.size()-1;
        //toLower(s);
        //cout<<s;
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        while(l<h){
            if (!isalnum(s[l])) {
            l++;
            continue;
            }
            if (!isalnum(s[h])) {
                h--;
                continue;
            }
            if(s[l]!=s[h])return false;
            l++;
            h--;
        }
        return true;
    }
};