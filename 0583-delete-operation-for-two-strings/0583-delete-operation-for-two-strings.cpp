class Solution {
public:
    int minDistance(string word1, string word2) {
        int n =word1.size();
        int m = word2.size();

        vector<vector<int>>arr(n+1 , vector<int>(m+1 , 0));

        for(int i=1 ;i<=n;i++){
            for(int j = 1;j<=m;j++){

                if(word1[i-1] == word2[j-1]){
                    arr[i][j] = arr[i-1][j-1]+1;
                }
                else if(word1[i-1] != word2[j-1]){
                    arr[i][j] = max(arr[i][j-1] , arr[i-1][j]);
                }
            }
        }

        return (n- arr[n][m])+ (m- arr[n][m]);
    }
};