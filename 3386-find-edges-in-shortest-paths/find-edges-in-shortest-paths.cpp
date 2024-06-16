#define ll long long 
class Solution {
public:
    vector<ll>find(int s, int n, vector<pair<int, ll>>adj[]){
       priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> pq;
        vector<int> vis(n, 0);
        vector<ll> dis(n, INT_MAX);
        dis[s] = 0;
        pq.push({0, s});
        while (!pq.empty()) {
            int s = pq.size();
            while(s--){
                int node = pq.top().second;
                ll wt = pq.top().first;
                pq.pop();
                if (vis[node] == 1) {
                    continue;
                }
                vis[node] = 1;
                for (auto i : adj[node]) {
                    int neighbour = i.first;
                    ll weight = i.second;
                    if (wt + weight < dis[neighbour]) {
                        dis[neighbour] = wt + weight;
                        pq.push({dis[neighbour], neighbour});
                    }
                }
            }
        }
        return dis;
    }
    vector<bool> findAnswer(int n, vector<vector<int>>& edges) {
        vector<bool>ans(edges.size(), 0);
        vector<pair<int, ll>>adj[n];
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back({edges[i][1], edges[i][2]});
            adj[edges[i][1]].push_back({edges[i][0], edges[i][2]});
        }
        vector<ll>start = find(0, n, adj);
        vector<ll>end = find(n-1, n, adj);
        for(int i=0; i<edges.size(); i++){
            if(edges[i][2]+start[edges[i][0]]+end[edges[i][1]]==start[n-1]){
                ans[i] = 1;
            }
            if(edges[i][2]+start[edges[i][1]]+end[edges[i][0]]==start[n-1]){
                ans[i] = 1;
            }
        }
        return ans;
    }
};