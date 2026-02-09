class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();

        queue<pair<int, int>>q;

        int f=0, r=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==1){
                    f++;
                }
                else if(grid[i][j]==2){
                    r++;
                    q.push({i, j});
                }
            }
        }
        if(f==0)return 0;
        int ans=0;
        vector<int>dx {1, -1, 0 , 0};
        vector<int>dy = {0 , 0, 1, -1};

        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){
                
                pair<int, int>temp = q.front();
                q.pop();

                for(int j=0;j<4;j++){

                    int nx = dx[j]+temp.first;
                    int ny = dy[j]+temp.second;

                    if(nx>=0 && nx< n && ny>=0 && ny<m && grid[nx][ny]==1){
                        f--;
                        q.push({nx, ny});
                        grid[nx][ny]=2;
                    }
                }
            }if(!q.empty())ans++;
        }
        if(f!=0)return -1;
        return ans;
    }
};