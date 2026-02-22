class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int>freq(26, 0);

        int max_f=0, max_l =0;
        int l =0;

        for(int r=0;r<n;r++){
            freq[s[r]-'A']++;
            max_f = max(max_f , freq[s[r]-'A']);

            if( ((r-l+1)- max_f) > k){
                freq[s[l]-'A']--;
                l++;
            }

            if( ((r-l+1)- max_f) <= k){
                max_l = max(max_l , (r-l+1));
            }
        }

        return max_l;
    }
};