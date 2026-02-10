class Solution {
public:
    string minWindow(string s, string t) {
        int n = s.size();
        int m = t.size();
        if (m > n) return "";

        int c=0, s_i =-1, min_len = INT_MAX , l=0, r=0;
        vector<int>arr(256,0);
       
        for(char c:t) arr[c]++;

        while(r<n){
            if(arr[s[r]] > 0)c++;
            arr[s[r]]--;
            r++;
            while(c==m){

                if((r-l)<min_len){
                    min_len = r-l;
                    s_i = l;
                }
                arr[s[l]]++;
                if(arr[s[l]] >0)c--;
                l++;
            }
        }
        return (s_i==-1) ?"" : s.substr(s_i, min_len);
        
    }
};