class Solution {
public:
    string minWindow(string s, string t) {
        
        int n = s.size();
        int m = t.size();

        vector<int>freq(256, 0);
        for(char c: t)freq[c]++;

        int l =0, r=0;
        int c=0;
        int s_i = -1 , min_len = INT_MAX;

        while(r<n){

            if(freq[s[r]] > 0)c++;
            freq[s[r]]--;
            r++;

            while(c == m){

                if((r-l)< min_len){
                    min_len = r-l;
                    s_i = l;
                }

                freq[s[l]]++;
                if(freq[s[l]]>0)c=c-1;
                l++;
            }
            
        }

        return (s_i == -1)?"" : s.substr(s_i, min_len);
    }
};