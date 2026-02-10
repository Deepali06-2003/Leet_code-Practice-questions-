class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        if(s1.size()>s2.size())return false;

        vector<int>s1_f(25,0);
        for(int i=0;i<s1.size();i++){
            s1_f[s1[i]-'a']++;
        }

        int l=0, r = s1.size()-1;
        while(r<s2.size()){

            string x = s2.substr(l, r-l+1);
            
            vector<int>s2_f(25,0);
            for(int i=0;i<x.size();i++){
                s2_f[x[i]-'a']++;
            }

            if(s2_f == s1_f)return true;
            l++;
            r++;
        }return false;
    }
};