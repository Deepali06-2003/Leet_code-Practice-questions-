class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();
        if(n>m)return false;

        vector<int>s1_f(26,0);
        for(int i=0;i<s1.size();i++){
            s1_f[s1[i]-'a']++;
        }
        
        vector<int>s2_f(26,0);

        int i=0, j=0;
        while(j<m){

            s2_f[s2[j]-'a']++;

            if((j-i+1)>n){
                s2_f[s2[i]-'a']--;
                i++;
            }

            if(s1_f == s2_f)return true;
            j++;
        }  
        return false;
    }
};