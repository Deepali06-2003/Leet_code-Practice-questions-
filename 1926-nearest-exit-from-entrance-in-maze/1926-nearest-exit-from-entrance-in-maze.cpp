class Solution {
public:
    int nearestExit(vector<vector<char>>& maze, vector<int>& entrance) {
        int n = maze.size();
        int m = maze[0].size();
        int ans=0;

        queue<pair<int , int>>q;
        
        q.push({entrance[0], entrance[1]}) ;
        maze[entrance[0]][entrance[1]] = '+';

        vector<int>dx = {0, 0, 1, -1};
        vector<int>dy = {1, -1, 0, 0};

        while(!q.empty()){

            int s = q.size();
            for(int i=0;i<s;i++){

                pair<int, int>temp = q.front();
                q.pop();
                
                for(int j =0;j<4;j++){
                    int nx = dx[j]+temp.first;
                    int ny = dy[j]+temp.second;

                    if(nx>=0 && nx<n && ny>=0 && ny<m && maze[nx][ny]=='.'){
                        maze[nx][ny]='+';
                        q.push({nx, ny});

                        if(nx ==0 || nx== n-1 || ny==0 || ny==m-1)return ans+1;
                    }
                }
            }ans++;
        }return -1;

    }
};