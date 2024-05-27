class Solution {
public:
    bool dfs(int node, vector<int>adj[], vector<int>&color){
        for(auto i:adj[node]){
            if(color[i]==-1){
                color[i] = (color[node]+1)%2;
                if(dfs(i, adj, color)==0){
                    return 0;
                }
            }
            else if(color[i]==color[node]){
                return 0;
            }
        }
        return 1;
    }
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        vector<int>adj[n+1];
        for(auto i:dislikes){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }

        vector<int>color(n+1, -1);
        for(int i=1; i<=n; i++){
            if(color[i]==-1){
                color[i] = 0;
                if(dfs(i, adj, color)==0){
                    return 0;
                }
            }
        }
        return 1;
    }
};