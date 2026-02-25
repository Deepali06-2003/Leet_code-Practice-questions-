class Solution {
public:

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        vector<vector<int>>adj(numCourses);
        for(int i =0;i<prerequisites.size();i++){
            adj[prerequisites[i][0]].push_back(prerequisites[i][1]);
        }

        vector<int>indegree(numCourses, 0);
        queue<int>q;

        for(int i =0;i<numCourses;i++){
           for(auto j : adj[i]) indegree[j]++;
        }
        for(int i=0;i<numCourses;i++){
            if(indegree[i] ==0) q.push(i);
        }


        vector<int>res;
        while(!q.empty()){
            int x = q.front();
            q.pop();

            res.push_back(x);

            for(auto j : adj[x]){
                indegree[j]--;
                if(indegree[j] == 0)q.push(j);
            }

        }

        return res.size() == numCourses;
    }
};