class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();

        vector<int>freq(256, 0);
        if(m >n)return "";

        for(char c: t) freq[c]++;

        int s_i = -1 , le = INT_MAX;
        int c=0;

        int l =0 , r=0;
        while(r < n){

            if(freq[s[r]] > 0)c++;
            freq[s[r]]--;
            r++;

            while(c==m){
                if((r-l) < le){
                    s_i = l;
                    le = r-l;
                }

                freq[s[l]]++;
                if(freq[s[l]]>0)c--;
                l++;

            }
        }
        if(s_i == -1)return "";
        return s.substr(s_i , le);
    }
};