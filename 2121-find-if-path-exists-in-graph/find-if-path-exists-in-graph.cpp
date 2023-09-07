class Solution {
public:
    bool dfs(int src, int des, vector<int>adj[], vector<int>&vis){
        if(src == des){
            return true;
        }
        for(auto i:adj[src]){
            if(!vis[i]){
                vis[i] = 1;
                if(dfs(i, des, adj, vis)==true){
                    return true;
                }
            }
        }
        return false;
    }
    bool validPath(int n, vector<vector<int>>& edges, int src, int des) {
        vector<int>adj[n];
        for(auto i:edges){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        vector<int>vis(n,0);
        return dfs(src, des, adj, vis);
    }
};