class Solution {
public:
void backtrack(vector<vector<int>>& grid , int n , int m , int i , int j , int& obs , int& res , int count){
    if(i<0 || i>= n || j<0 || j>= m || grid[i][j] == -1)return;

    if(grid[i][j] ==2 ){
        if(count == obs)res++;
        return;
    }

    grid[i][j] = -1;
    count++;

    backtrack(grid , n , m , i+1 , j, obs , res , count);
    backtrack(grid , n , m , i-1 , j, obs , res , count);
    backtrack(grid , n , m , i , j+1, obs , res , count);
    backtrack(grid , n , m , i , j-1, obs , res , count);

    grid[i][j] =0;
    count--;


}
    int uniquePathsIII(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        int x = 0 , y =0;
        int obs =0;
        int res =0;

        for(int i =0 ; i<n;i++){
            for(int j =0 ;j<m;j++){
                if(grid[i][j] == 0) obs++;
                else if(grid[i][j] == 1){
                    obs++;
                    x= i;
                    y = j;
                }
            }
        }
        backtrack(grid , n , m , x , y , obs , res , 0);
        return res;
    }
};