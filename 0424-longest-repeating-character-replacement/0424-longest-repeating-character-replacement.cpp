class Solution {
public:
    int characterReplacement(string s, int k) {
        int n = s.size();
        vector<int>freq(26, 0);

        int max_l = 0 , max_freq = 0;

        int l =0 ;
        for(int r =0 ;r<n ;r++){

            freq[s[r] - 'A']++;
            max_freq = max(max_freq , freq[s[r] - 'A']);

            if( ((r-l+1) - max_freq )> k){
                freq[s[l] - 'A']--;
                l++;
            }
            if( ((r-l+1) - max_freq )<= k){
                max_l = max(max_l , (r-l+1));
            }

   
        }
        return max_l;
    }
};