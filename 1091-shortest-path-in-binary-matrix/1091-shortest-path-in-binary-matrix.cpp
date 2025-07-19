class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        if(grid[0][0] == 1 || grid[n-1][m-1] == 1)return -1;

        queue<pair<int,int>>q;

        q.push({0,0});

        vector<int> dx ={-1 ,1,0,0,-1,1,-1,1};
        vector<int>dy = {0,0,-1,1,-1,1,1,-1};
        int ans=1;

        while(!q.empty()){
            int size= q.size();
            for(int i =0;i<size;i++){

                pair<int , int> node = q.front();
                q.pop();
                int node_i = node.first;
                int node_j = node.second;
                if(node_i == n-1 && node_j == m-1)return ans;

                for(int j=0;j<8;j++){
                    int x = node_i + dx[j];
                    int y = node_j + dy[j];

                    if(x>=0 && x<n && y>= 0 && y<m && grid[x][y] == 0){
                        grid[x][y] = 1;
                        q.push({x, y});
                    }
                }
            }
             ans++;
        }
        return -1;
    }
};