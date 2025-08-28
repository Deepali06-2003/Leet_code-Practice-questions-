class Solution {
public:
bool palindrome(string s, int l , int h){
    while(l<=h){
        if(s[l]!= s[h])
        return false;

        l++;
        h--;
    }
    return true;
}
void result(string s , vector<vector<string>>& res , vector<string>& temp , int start){
    if(start== s.size()){
        res.push_back(temp);
        return;
    }

    for(int i=start;i<s.size();i++){
        if(palindrome(s , start , i)){

        
        temp.push_back(s.substr(start, i - start + 1));
        result(s, res, temp , i+1);
        temp.pop_back();
    }
    }
}
    vector<vector<string>> partition(string s) {
        vector<vector<string>>res;
        vector<string> temp;

        result(s , res, temp , 0);

        return res;

    }
};