class Solution {
public:
int ans=0;

void helper(string s, int l , int h){
    while(l>=0 && h<s.size() && s[l]==s[h]){
        ans++;
        l--;
        h++;
    }
}
    int countSubstrings(string s) {
        
        for(int i =0;i<s.size();i++){
            helper(s, i, i);
            helper(s, i , i+1);
        }
        return ans;
    }
};