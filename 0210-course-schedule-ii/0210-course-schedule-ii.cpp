class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
         vector<vector<int>> adj(numCourses);

    for(auto &p : prerequisites){
        adj[p[1]].push_back(p[0]);
    }

        
        vector<int>indegree(numCourses, 0);
        for(int i =0;i<numCourses;i++){
            for(auto j:adj[i]){ indegree[j]++; }
        }
        queue<int>q; vector<int>res;
        for(int i =0;i<numCourses;i++){
            if(indegree[i]==0) q.push(i);
        }
        while(!q.empty()){
            int x = q.front();
            q.pop();

            res.push_back(x);

            for(auto j: adj[x]){
                indegree[j]--;
                if(indegree[j]==0)q.push(j);
            }
        }

        if(res.size() != numCourses)return {};
        return res;
    }
};
