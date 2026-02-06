class Solution {
public:
string helper(string ans , string s){
    int n = ans.size();
    int m = s.size();
    int i =0, j=0;

    string str ="";
    while(i<n && j<m){
        if(ans[i]==s[j]){
            str = str+ ans[i];
            i++;
            j++;
        }
        else return str;
    }
    return str;
}

    string longestCommonPrefix(vector<string>& strs) {
        int n = strs.size();

        string ans = strs[0];
        for(int i =1;i<n;i++){
            ans = helper(ans , strs[i]);
        }
        return ans;
    }
};