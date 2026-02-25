class Solution {
public:
bool possible(vector<vector<int>>& grid ,vector<vector<bool>>& visited , int n , int x , int y , int t){
    if(x<0 || x>=n || y<0 || y>=n || visited[x][y]==true || grid[x][y] > t)return false;

    visited[x][y]=true;

    // reached end
    if(x == n-1 && y == n-1)return true;

    vector<int>dx = {0, 0, 1, -1};
    vector<int>dy = {1, -1, 0, 0};

    for(int k =0;k<4;k++){
        int nx = x+ dx[k];
        int ny = y + dy[k];

        if(possible(grid, visited, n , nx, ny, t))return true;
    }
    return false;
}
    int swimInWater(vector<vector<int>>& grid) {
        int n = grid.size();
        int ans =0;

        int l = grid[0][0];
        int h = (n*n)-1;

        while(l<=h){
            int m = (l+h)/2;

            vector<vector<bool>>visited(n , vector<bool>(n , false));
            if(possible(grid , visited, n ,0, 0, m)){
                ans = m;
                h = m-1;
            }
            else l = m+1;
        }
        return ans;
    }
};