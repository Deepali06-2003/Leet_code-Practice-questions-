class Solution {
public:
    bool isValid(string s) {
        stack<int>st;

        for(char c: s){
            if(c =='(' || c=='{' || c=='[') st.push(c);

            else{
                if(!st.empty()){
                    char x = st.top();
                    if( (x=='(' && c==')') || (x=='{' && c=='}') || (x=='[' && c==']'))
                    st.pop();

                    else{
                        return false;
                    }
                }
                else{
                    st.push(c);
                }

                
            
            }
        }
        if(st.empty())return true;
        return false;
    }
};