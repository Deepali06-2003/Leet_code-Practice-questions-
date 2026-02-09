class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();

        queue<pair<int, int>>q;

        if(grid[0][0]==1 || grid[n-1][n-1]==1)return -1;

        vector<int>dx = {1, -1, 0 , 0 , -1 , 1, -1 , 1};
        vector<int>dy = {0 , 0 , 1 , -1, -1 , 1, 1, -1 };

        int ans =1;
        q.push({0 ,0});

        while(!q.empty()){
            int s = q.size();

            for(int i=0;i<s;i++){
                pair<int, int>temp = q.front();
                q.pop();

                if(temp.first==n-1 && temp.second == n-1)return ans;

                for(int j=0;j<8;j++){
                    int nx = temp.first + dx[j];
                    int ny = temp.second+ dy[j];

                    if(nx>=0 && nx<n && ny>=0 && ny<n && grid[nx][ny]==0){
                        grid[nx][ny]=1;
                        q.push({nx, ny});
                    }
                }
            }
            ans++;
        }
        return -1;
    }
};