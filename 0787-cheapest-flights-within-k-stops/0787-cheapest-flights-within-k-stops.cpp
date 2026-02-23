class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        
        vector<vector<pair<int,int>>> adj(n);
        for(auto i:flights){
            adj[i[0]].push_back({i[1] , i[2] });
        }

        queue<pair<int , pair<int , int>>>q;
        vector<int>dist(n, INT_MAX);

        q.push({0, {src , 0}});
        dist[src]=0;

        while(!q.empty()){
            auto temp = q.front();
            q.pop();


            int stop = temp.first ;
            int node = temp.second.first;
            int d = temp.second.second;

            if(stop > k)continue;

            for(auto t : adj[node]){
                int edge = t.first;
                int cost = t.second;

                if(d + cost < dist[edge] && stop <= k){
                    dist[edge] = d+cost;
                 
                    q.push({stop + 1, {edge, d + cost}});
                }
            }
        }

        if(dist[dst]==INT_MAX)return -1;
        return dist[dst];

    }
};