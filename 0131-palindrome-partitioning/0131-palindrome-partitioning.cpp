class Solution {
public:
bool ifPalindrome(string s , int l , int h){
    while(l<=h){
        if(s[l] != s[h])return false;
        l++;
        h--;
    }
    return true;
}

void helper(string s , vector<vector<string>>& res, vector<string>& curr, int x){
if(x == s.size()){
    res.push_back(curr);
    return;
}
    for(int i = x;i< s.size();i++){
        if(ifPalindrome(s , x, i)){
            curr.push_back(s.substr(x , i-x+1));

            helper(s , res , curr , i+1);
            curr.pop_back();
        }
    }
}


    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string>curr;

        if(s.empty())return res;

        helper(s , res , curr , 0);
        return res;
    }
};