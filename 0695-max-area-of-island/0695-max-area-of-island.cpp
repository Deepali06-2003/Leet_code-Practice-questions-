class Solution {
public:

void DFS(vector<vector<int>>& grid , int i , int j , int n , int m , int& t){
    if(i<0 || j<0 || i==n || j==m || grid[i][j]==0) return;
    
         t++;
        grid[i][j]=0;

     DFS(grid , i+1 , j, n , m , t);
     DFS(grid , i , j-1 , n , m , t);
     DFS(grid , i-1 , j , n , m , t);
     DFS(grid , i , j+1 , n , m , t);


}
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        int ans=0;
        

        for(int i=0;i<n;i++){
            for(int j =0 ;j<m ;j++){
                if(grid[i][j] == 1){
                    int t=0;
                    DFS(grid , i , j , n , m , t);
                    ans = max(ans , t);
                }
            }
        }

        return ans;
    }
};