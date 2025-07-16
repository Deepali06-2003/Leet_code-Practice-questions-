class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int n = s1.size();
        int m = s2.size();

        vector<vector<int>>arr(n+1 , vector<int>(m+1 , 0));

        for(int i=1;i<=n;i++){
            arr[i][0]= arr[i-1][0]+ s1[i-1];
           
        }

        for(int i=1;i<=m;i++)arr[0][i] = arr[0][i-1]+ s2[i-1];

        for(int i=1;i<=n;i++){
            for(int j=1;j<=m;j++){
                if(s1[i-1] == s2[j-1]){
                    arr[i][j]= arr[i-1][j-1];
                }
                else 
                arr[i][j] =  min(arr [i-1][j] + s1[i-1], arr[i][j-1] + s2[j-1]);

                cout<<arr[i][j]<<' ';
            }
            cout<<"\n";
        }
        return (arr[n][m]);
    }
};