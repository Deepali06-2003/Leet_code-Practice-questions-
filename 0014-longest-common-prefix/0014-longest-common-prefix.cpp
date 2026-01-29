class Solution {
public:
string helper(string s1, string s2){
    int i=0, j=0;
    int n = s1.size();
    int m = s2.size();

    if(s1.empty() || s2.empty())return "";
    
    string curr = "";

    while(i<n && j<m){
        if(s1[i]==s2[j]){
            curr.push_back(s1[i]);
            i++;
            j++;
        }
        else return curr;
    }
    return curr;

}
    string longestCommonPrefix(vector<string>& strs) {
        string ans = strs[0];

        for(int i =1;i<strs.size();i++){
            ans= helper(ans, strs[i]);
        }return ans;
    }
};