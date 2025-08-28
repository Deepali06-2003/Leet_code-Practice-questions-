class Solution {
public:
void helper(int k , int n , int x ,int s, vector<int>& curr , vector<vector<int>>& res){

    if(s == 0){
        if(curr.size() == k){
            res.push_back(curr);
        }
        return;
    }

    for(int i = x ; i<= 9 ;i++){
        if(i > s)break;
        curr.push_back(i);
        helper(k , n , i+1 , s- i , curr , res);
        curr.pop_back();
    }

}
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> curr ;
         vector<vector<int>> res;

        helper(k , n , 1 , n , curr , res);
        return res;
    }
};