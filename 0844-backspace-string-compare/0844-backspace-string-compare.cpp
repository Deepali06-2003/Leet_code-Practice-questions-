class Solution {
public:
    bool backspaceCompare(string s, string t) {
        stack<char>s1;
        stack<char>s2;

        for(char i:s){
            if(i=='#'){
                if(!s1.empty())s1.pop();
            }else{
                s1.push(i);
            }
        }

        for(char i:t){
            if(i=='#'){
                if(!s2.empty())s2.pop();
            }else{
                s2.push(i);
            }
        }

        return s1==s2;
    }
};