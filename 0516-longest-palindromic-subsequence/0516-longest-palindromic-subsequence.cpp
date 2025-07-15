class Solution {
public:
    int longestPalindromeSubseq(string s) {
        string x = s;
        reverse(s.begin() , s.end());

        int n = s.size();
        vector<vector<int>> arr(n+1 , vector<int>(n+1 , 0));

        for(int i= 1;i<= n;i++){
            for(int j = 1;j<=n;j++){

                if(s[i-1] == x[j-1]){
                    arr[i][j]= arr[i-1][j-1]+1;
                }

                else if(s[i-1]!= x[j-1]){
                    arr[i][j]= max(arr[i-1][j] , arr[i][j-1]);
                }

            }
        }
        return arr[n][n];
    }
};