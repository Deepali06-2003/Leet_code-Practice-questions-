class Solution {
public:
int prims(int v , vector<vector<pair<int, int>>>& adj){

    priority_queue< pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    vector<int> visited(v, 0);

    pq.push({0 , 0});
    int sum =0;
    while(!pq.empty()){

        auto temp = pq.top();
        pq.pop();

        int w = temp.first;
        int node = temp.second;

        if(visited[node])continue;

        visited[node]=1;           // ---> if not visited
        sum = sum + w;              // add to result

        //now explore the adj nodes
        for(auto& j : adj[node]){
            
            int edge = j.first;
            int cost = j.second;

            if(!visited[edge]) pq.push({ cost , edge });
        }
    }

    return sum;
}



    int minCostConnectPoints(vector<vector<int>>& points) {
        
        int v= points.size();
        vector<vector<pair<int, int>>>adj(v);
        for(int i=0;i<v-1;i++){
            for(int j =i+1;j<v;j++){

                int x1 = points[i][0];
                int y1 = points[i][1];

                int x2 = points[j][0];
                int y2 = points[j][1];

                int dst = abs(x1 - x2) + abs(y1 - y2);
                adj[i].push_back({j , dst});
                adj[j].push_back({i , dst});
            }
        }

        return prims(v , adj);
    }
};