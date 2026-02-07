class Solution {
public:
    string shortestPalindrome(string s) {
        
        string rev = s;
        reverse(rev.begin(), rev.end());

        for(int i=0;i<s.size();i++){
                    // s substring start frm 0 ind,   rev substring start from i ind, length 
                    // 
            
            if(memcmp(s.c_str() , rev.c_str()+i , s.size()-i ) ==0)return rev.substr(0 , i)+s;
        }return rev+s;
    }
};