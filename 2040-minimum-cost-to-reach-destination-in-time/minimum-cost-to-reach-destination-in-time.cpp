int dp[1001][1001];
class Solution {
    vector<bool> vis;
    int solve(vector<pair<int, int>> adj[], vector<int> &pf, int u, int t) {
        if(t < 0)
            return 1e7;
        
        if(u == 0)
            return 0;
        
        if(dp[u][t] != -1)
            return dp[u][t];

        vis[u] = 1;

        int ans = 1e7;
        for(auto &[v, w]: adj[u])   
            if(w <= t) {
                ans = min(ans, pf[v] + solve(adj, pf, v, t - w));
            }
        
        vis[u] = 0;

        return dp[u][t] = ans;
    }

public:
    int minCost(int maxTime, vector<vector<int>>& edges, vector<int>& passingFees) {
        int n = passingFees.size();
        vector<pair<int, int>> adj[n];
        for(auto &e: edges) {
            adj[e[0]].push_back({e[1], e[2]});
            adj[e[1]].push_back({e[0], e[2]});
        }

        memset(dp, -1, sizeof dp);
        vis.resize(n);
        int ans = passingFees.back() + solve(adj, passingFees, n-1, maxTime);
        if(ans <= 1e7)
            return ans;
        
        return -1;
    }
};