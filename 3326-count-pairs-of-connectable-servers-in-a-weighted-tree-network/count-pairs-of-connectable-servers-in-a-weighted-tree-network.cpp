class Solution {
public:
    void dfs(int node, int w, vector<int>&vis, vector<pair<int, int>>adj[], int &s, int &c){
        if(w%s==0)c++;
        vis[node] = 1;
        for(auto i:adj[node]){
            if(!vis[i.first]){
                dfs(i.first, i.second+w, vis, adj, s, c);
            }
        }
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int signalSpeed) {
        int n = edges.size()+1;
        vector<pair<int, int>>adj[n];
        for(auto i:edges){
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        vector<int>ans(n, 0);
        for(int i=0; i<n; i++){
            vector<int>vis(n, 0);
            vector<int>v;
            for(auto it:adj[i]){
                int c = 0;
                vis[i] = 1;
                dfs(it.first, it.second, vis, adj, signalSpeed, c);
                v.push_back(c);
            }
            int sum=0;
            for(int k=0;k<v.size();k++){
                for(int j=0;j<v.size();j++){
                    if(k!=j){
                        sum+=v[k]*v[j];
                    }
                }
            }
            ans[i]=sum/2;
        }
        return ans;
    }
};