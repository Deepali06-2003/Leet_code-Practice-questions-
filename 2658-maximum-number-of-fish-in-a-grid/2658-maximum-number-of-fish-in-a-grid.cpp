class Solution {
public:
void dfs(vector<vector<int>>& grid , int i , int j , int n , int m , int& temp){
    if(i<0 || j<0 || i== n|| j==m || grid[i][j] == 0){
        return;
    }
    temp = temp+ grid[i][j];
    grid[i][j] =0;

    dfs(grid , i+1 , j, n,m, temp);
    //dfs(grid , i+1 , j+1, n,m, temp);
    dfs(grid , i , j+1, n,m, temp);
    //dfs(grid , i-1 , j+1, n,m, temp);
    dfs(grid , i-1 , j, n,m, temp);
    //dfs(grid , i-1 , j-1, n,m, temp);
    dfs(grid , i , j-1, n,m, temp);
    //dfs(grid , i+1 , j-1, n,m, temp);


}
    int findMaxFish(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans=0;

        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(grid[i][j]> 0){
                    int temp =0;
                    dfs(grid , i , j , n , m, temp);
                    ans = max(temp , ans);
                }
            }
        }
        return ans;
    }
};