class Solution {
public:
bool dfs(vector<vector<int>>& adj , vector<int>& vist , int x, int y){
    
    if(x == y)return true;

    vist[x]=1;
    for(auto i : adj[x]){
        if(!vist[i]){
            if(dfs(adj, vist , i , y))return true;
        }
    }
    return false;

}
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();
        vector<vector<int>>adj(n+1);

        for(int i=0;i<n;i++){

            int u = edges[i][0] , v = edges[i][1];    
            vector<int>vist(n+1, 0);

            if(dfs(adj , vist , u , v)) return edges[i];

            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        return {};
    }
};