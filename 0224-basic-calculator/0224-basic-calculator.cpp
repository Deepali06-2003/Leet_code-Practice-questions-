# define pii pair<int,int>

class Solution {
public:
int calculate(string s) {
long long int sum = 0;
int sign = 1;
stack<pii> st;
for(int i = 0; i < s.length(); i++){
if(isdigit(s[i])){
long long temp = 0;
while(i < s.size() && isdigit(s[i])){
temp = temp * 10 + (s[i] - '0');
i++;
}
i--;
sum += (temp * sign);
sign = 1;
}
else if(s[i] == '('){
st.push({sum, sign});
sum = 0;
sign = 1;
}
else if(s[i] == ')'){
sum = st.top().first + (st.top().second * sum);
st.pop();
}
else if(s[i] == '-') sign = (-1 * sign);
}
return sum;

}
};