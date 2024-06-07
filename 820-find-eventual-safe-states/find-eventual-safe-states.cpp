class Solution {
public:
    bool dfs(int node, vector<int>&vis, vector<int>&path, vector<int>&isSafe, vector<int>adj[]){
        vis[node] = 1;
        path[node] = 1;
        for(auto i:adj[node]){
            if(!vis[i]){
                if(dfs(i, vis, path, isSafe, adj)==1){
                    return 1;
                }
            }
            else if(path[i]==1){
                return 1;
            }
        }
        path[node] = 0;
        isSafe[node] = 1;
        return 0;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int>adj[n];
        for(int i=0; i<n; i++){
            for(auto j:graph[i]){
                adj[i].push_back(j);
            }
        }
        vector<int>vis(n, 0);
        vector<int>path(n, 0);
        vector<int>isSafe(n, 0);
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                dfs(i, vis, path, isSafe, adj);
            }
        }
        for(int i=0; i<n; i++){
            if(isSafe[i]==1){
                ans.push_back(i);
            }
        }
        return ans;
    }
};