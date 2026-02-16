class Solution {
public:
    int characterReplacement(string s, int k) {
        
        int ans=0 , max_freq=0;
        int l=0, r=0;
        vector<int>freq(26, 0);

        while(r< s.size()){
            freq[s[r] - 'A']++;
            max_freq = max(max_freq , freq[s[r] - 'A']);

            if((r-l+1)-max_freq > k){
                freq[s[l]-'A']--;
                l++;
            }

            if((r-l+1)-max_freq <= k){
                ans= max(ans , (r-l+1));
            }
            r++;

        }return ans;
    }
};