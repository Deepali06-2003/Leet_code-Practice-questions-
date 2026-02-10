class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())return false;

        sort(s1.begin(), s1.end());

        int l=0, r = s1.size()-1;
        while(r<s2.size()){

            string x = s2.substr(l, r-l+1);
            sort(x.begin(), x.end());

            if(x == s1)return true;
            l++;
            r++;
        }return false;
    }
};