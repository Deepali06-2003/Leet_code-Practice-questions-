class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        queue<pair<int,int>>q;

        for(int i=0;i<n ;i++){
            for(int j =0;j<m;j++){
                if(mat[i][j] == 0) q.push({i, j});
                else mat[i][j] = -1;
                
            }
        }
        vector<int>dx ={0,0,1,-1};
        vector<int>dy={1,-1,0,0};

        while(!q.empty()){
            int size = q.size();
            for(int i =0;i<size;i++){

                pair<int,int>node = q.front();
                q.pop();
                int r = node.first;
                int c = node.second;

                for(int j =0;j<4;j++){

                    int x = r+ dx[j];
                    int y = c+dy[j];

                    if(y>=0 && y<m && x>=0 && x<n && mat[x][y] ==-1  ){
                        
                            mat[x][y] = mat[r][c] + 1;
                            q.push({x, y});
                        
                    }
                }
            }
        }
        return mat;
    }
};