class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<vector<int>>& adj){
        vis[node] = 1;
        for(auto i:adj[node]){
            if(!vis[i]){
                dfs(i, vis, adj);
            }
        }
    }
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<int>vis(n,0);
        
        dfs(0, vis, rooms);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};