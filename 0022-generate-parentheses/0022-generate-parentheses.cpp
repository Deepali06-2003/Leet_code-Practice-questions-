class Solution {
public:
void result(int n , vector<string>&res , string curr , int open , int close ){
    if(n == close){
        res.push_back(curr);
        return;
    }
    
    if(open<n){
        curr.push_back('(');
        result(n , res , curr , open+1 , close );
        curr.pop_back();
        
    }
    if(open>close){
        curr.push_back(')');
        result(n , res , curr ,open , close+1 );
       curr.pop_back();
    }
    
}

    vector<string> generateParenthesis(int n) {

     
     vector<string> res;
     string curr;

     result(n, res , curr , 0 , 0 );   
     return res;
    }
};