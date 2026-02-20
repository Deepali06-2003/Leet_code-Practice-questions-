class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        
        int n = maze.size();
        int m = maze[0].size();

        queue<pair<int, int>>q;
        q.push({entrance[0], entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        vector<int>dx = {0, 0, 1, -1};
        vector<int>dy = {1, -1, 0 , 0};
        int c=1;

        while(!q.empty()){
            int s = q.size();
            for(int i=0;i<s;i++){

                pair<int, int> x = q.front();
                q.pop();

                for(int j =0;j<4 ;j++){

                    int nx = x.first + dx[j];
                    int ny = x.second + dy[j];
                    if(nx>=0 && nx<n && ny>=0 && ny< m && maze[nx][ny]=='.'){
                    if(nx== n-1 || nx==0 || ny==0 || ny == m-1){return c;}
                        
                        q.push({nx, ny});
                        maze[nx][ny]= '+';
                    }
                }
            }
            c++;
        }
        return -1;
    }
};