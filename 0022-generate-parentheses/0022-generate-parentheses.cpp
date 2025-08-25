class Solution {
public:

void helper(int n , vector<string>&ans , string& str, int o , int c){
    if(n == c){
        ans.push_back(str);
        return;
    }

    if(o < n){
        str = str+"(";
        helper(n , ans , str , o+1 , c);
        str.pop_back();
    }

    if(c<o){
        str = str+")";
        helper(n , ans , str , o , c+1);
        str.pop_back();
    }
}
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string str;
        if(n==0)return ans;

        helper(n , ans , str, 0 , 0);
        return ans;
    }
};