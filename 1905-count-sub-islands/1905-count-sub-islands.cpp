class Solution {
public:
void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2 , int i , int j , int n , int m , bool& isbool){

    if(i<0 || j<0 || i== n|| j==m || grid2[i][j]==0)return;

    if(grid1[i][j]!=1)isbool = false;

    grid2[i][j]=0;
    grid1[i][j]=0;

    dfs(grid1 , grid2 , i+1 , j , n , m , isbool);
    dfs(grid1 , grid2 , i , j+1 , n , m , isbool);
    dfs(grid1 , grid2 , i-1 , j , n , m , isbool);
    dfs(grid1 , grid2 , i , j-1 , n , m , isbool);

}
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid2.size();
        int m = grid2[0].size();
        int c=0;

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid2[i][j] ==1){
                    bool isbool = true;
                    dfs(grid1 , grid2 , i , j , n, m, isbool);
                    if(isbool)c++;
                }
            }
        }
        return c;
    }
};