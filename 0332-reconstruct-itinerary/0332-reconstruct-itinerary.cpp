class Solution {
public:

    unordered_map<string, multiset<string>> adj;
    vector<string> route;

    void dfs(string node) {

        while(!adj[node].empty()){
            string next = *adj[node].begin();
            adj[node].erase(adj[node].begin());
            dfs(next);
        }

        route.push_back(node);
    }


    vector<string> findItinerary(vector<vector<string>>& tickets) {
        
        adj.clear();
        route.clear();

        for(auto &t : tickets){
            adj[t[0]].insert(t[1]);
        }

        dfs("JFK");

        reverse(route.begin(), route.end());
        return route;
    }
};