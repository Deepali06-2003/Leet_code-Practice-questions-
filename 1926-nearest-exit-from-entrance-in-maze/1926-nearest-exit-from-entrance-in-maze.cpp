class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();

        queue<pair<int, int>>q;
        q.push({entrance[0],entrance[1]});
        maze[entrance[0]][entrance[1]] = '+';

        int c=0;

        vector<int>dx={0 , 1, 0 , -1};
        vector<int>dy ={1 , 0 , -1 , 0};

        while(!q.empty()){  
            int sz = q.size();

            for(int i =0;i<sz;i++){

                pair<int,int>ele = q.front();
                q.pop();

                int ele_i = ele.first;
                int ele_j = ele.second;

                for(int j =0;j<4;j++){

                    int nx = ele_i + dx[j];
                    int ny = ele_j + dy[j];

                    if(nx>=0 && nx< n && ny>=0 && ny<m && maze[nx][ny] =='.'){
                        if (nx == 0 || ny == 0 || nx == n - 1 || ny == m - 1)return c + 1;
                        maze[nx][ny] = '+';
                        q.push({nx , ny});
                    }

                }
            }
            c++;
        }
        return -1;
    }
};