class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& f, int src, int dst, int k) {
        vector<pair<int, int>>adj[n];
        for(int i=0; i<f.size(); i++){
            adj[f[i][0]].push_back({f[i][1], f[i][2]});
        }
        
        queue<pair<int, pair<int, int>>>pq;
        pq.push({0, {src, 0}});
        vector<int>dis(n, INT_MAX);
        dis[src] = 0;
        
        while(!pq.empty()){
            int stops = pq.front().first;
            auto [node, price] = pq.front().second;
            pq.pop();
            if(stops>k) continue;
            for(auto it:adj[node]){
                int newNode = it.first;
                int newPrice = it.second;
                if(dis[newNode]>newPrice + price && stops<=k){
                    dis[newNode] = newPrice + price;
                    pq.push({stops+1, {newNode, dis[newNode]}});
                }
            }
        }
        if(dis[dst]==INT_MAX)return -1;
        return dis[dst];
    }
};