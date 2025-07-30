class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        queue<pair<int , int>>q;
        int a = entrance[0];
        int b = entrance[1];
        maze[a][b] = '+';
        q.push({a,b});

        vector<int>dx = {0 , 0 , 1, -1};
        vector<int>dy = {1 , -1 , 0 , 0};

        int c=0;

        while(!q.empty()){
            int l = q.size();
            for(int i =0;i<l ;i++){

                pair<int,int>t = q.front();
                q.pop();
                int x = t.first;
                int y = t.second;

                for(int j =0;j<4;j++){
                    int nx = x + dx[j];
                    int ny = y+ dy[j];

                    if(nx>=0 && nx<n && ny>=0 && ny<m && maze[nx][ny] == '.'){
                        q.push({nx , ny});
                        maze[nx][ny] ='+';
                        if(nx==0 || nx==n-1 || ny==0 || ny==m-1)return c+1;
                    }
                }
            }c++;
        }
        return -1;

    }
};