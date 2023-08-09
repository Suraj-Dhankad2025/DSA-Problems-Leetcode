class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int, int>>adj[n];
        for(int i=0; i<flights.size(); i++){
            adj[flights[i][0]].push_back({flights[i][1], flights[i][2]});
        }
        queue<pair<int, pair<int, int>>>q;
        vector<int>dis(n,1e9);
        dis[src] = 0;
        q.push({src,{0,0}});
        while(!q.empty()){
            int node = q.front().first;
            int cost = q.front().second.first;
            int stops = q.front().second.second;
            q.pop();
            if(stops>k)continue;
            for(auto it:adj[node]){
                int wt = it.second;
                int adjNode = it.first;
                if(cost+wt<dis[adjNode] && stops<=k){
                    dis[adjNode] = wt+cost;
                    q.push({adjNode,{wt+cost,stops+1}});
                }
            }
        }
        if(dis[dst]==1e9)return -1;
        return dis[dst];
    }
};