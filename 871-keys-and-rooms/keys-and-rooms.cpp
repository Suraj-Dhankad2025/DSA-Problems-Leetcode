class Solution {
public:
    void dfs(int node, vector<int>& vis, vector<int>adj[]){
        if(vis[node]==1){
            return ;
        }
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
        vector<int>adj[n];
 
        for(int i=0; i<n; i++){
            for(auto it:rooms[i]){
                adj[i].push_back(it);
            }
        }
        dfs(0, vis, adj);
        for(int i=0; i<n; i++){
            if(!vis[i]){
                return false;
            }
        }
        return true;
    }
};