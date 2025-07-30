class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>>adj(numCourses);

        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];

            adj[u].push_back(v);
        }

        vector<int>indegree(numCourses, 0);
        for(int i =0;i<numCourses; i++){
            for(int j =0;j<adj[i].size() ;j++){
                int x = adj[i][j];
                indegree[x]++;
            }
        }

        queue<int>q;
        vector<int>res;
        for(int i =0;i<indegree.size();i++){
            if(indegree[i]==0)
            q.push(i);
        }

        while(!q.empty()){

            int t = q.front();
            q.pop();
            res.push_back(t);

            for(int i = 0 ; i< adj[t].size(); i++){
                int x = adj[t][i];
                indegree[x]--;
                if(indegree[x]==0)q.push(x);
            }
        }
        if(res.size() == numCourses)return true;
        return false;
    }
};