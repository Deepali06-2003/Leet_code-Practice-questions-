class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        
        int n = mat.size();
        int m = mat[0].size();

        queue<pair<int, int>>q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0)q.push({i, j});
                else mat[i][j]= -1;
            }
        }

        vector<int>dx = {0, 0, -1, 1};
        vector<int>dy = {1, -1,0, 0};

        while(!q.empty()){

            pair<int, int>t = q.front();
            q.pop();

            for(int j =0;j<4;j++){
                int nx = dx[j]+ t.first;
                int ny = dy[j]+t.second;

                if(nx>=0 && ny>=0 && ny<m && nx<n && mat[nx][ny]==-1){
                    mat[nx][ny]= mat[t.first][t.second]+1;
                    q.push({nx , ny});
                }
            }
        }

        return mat;
    }
};