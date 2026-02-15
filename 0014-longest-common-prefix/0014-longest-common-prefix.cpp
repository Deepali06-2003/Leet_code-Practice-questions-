class Solution {
public:
string helper( string& s1 , string& s2){
    string ans = "";

    int i=0, j=0;
    while(i<s1.size() && j <s2.size()){

        if(s1[i] == s2[j]){
            ans.push_back(s1[i]);
            i++;
            j++;
        }
        else return ans;
    }
    return ans;
}
    string longestCommonPrefix(vector<string>& strs) {
        string res = strs[0];
        int n = strs.size();

        for(int i=1;i<n;i++){
            res = helper(res , strs[i]);
        }return res;
    }
};