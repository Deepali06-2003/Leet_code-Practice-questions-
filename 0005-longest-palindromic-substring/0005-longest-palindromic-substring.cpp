class Solution {
public:
bool isPalindrome(string x, int l , int h){
    while(l<h){
        if(x[l]!=x[h])return false;
        l++;
        h--;
    }return true;
}
    string longestPalindrome(string s) {
        int n = s.size();

        if(n<=1)return s;

        auto helper =[&](int l , int h){
            while(l>=0 && h<n &&  (s[l]==s[h]) ){
                l--;
                h++;
            }return s.substr(l+1, h-l-1);
        };

        string ans = "";

        for(int i =0;i<n-1;i++){
            
                
            string odd = helper(i,i);
            string even = helper(i, i+1);

            if(odd.size()>ans.size())ans = odd;
            if(even.size()>ans.size())ans = even;
            
        }return ans;
    }
};