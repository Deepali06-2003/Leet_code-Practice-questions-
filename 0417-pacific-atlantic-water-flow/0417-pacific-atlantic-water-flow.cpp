class Solution {
public:
void helper(vector<vector<int>>& heights, queue<pair<int, int>>& q, vector<vector<bool>>& visited){
    int n = heights.size();
    int m = heights[0].size();

    vector<int>dx = {0, 0 , 1, -1};
    vector<int>dy ={1, -1, 0, 0};

    while(!q.empty()){

        pair<int, int>temp=q.front();
        q.pop();


        for(int j=0;j<4;j++){

            int nx = temp.first+dx[j];
            int ny = temp.second+ dy[j];

            if(nx>=0 && ny>=0 && nx<n && ny<m && heights[nx][ny] >= heights[temp.first][temp.second] && visited[nx][ny] == false){
                    q.push({nx, ny});
                    visited[nx][ny]= true;

            }
        }
    }

}
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        queue<pair<int, int>>pac_q;
        queue<pair<int, int>>atl_q;

        vector<vector<bool>>pac(n , vector<bool>(m, false));
        vector<vector<bool>>atl(n , vector<bool>(m, false));

        for(int i=0;i<n;i++){
            pac_q.push({i,0});
            pac[i][0]=true;

            atl_q.push({i, m-1});
            atl[i][m-1]= true;
        }

        for(int i=0;i<m;i++){
            pac_q.push({0,i});
            pac[0][i]=true;

            atl_q.push({n-1, i});
            atl[n-1][i]= true;
        }

        helper(heights, pac_q, pac);
        helper(heights, atl_q, atl);

        vector<vector<int>>res;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(atl[i][j]==true && pac[i][j]==true)res.push_back({i, j});
            }
        }

        return res;
        
    }
};