class Solution {
public:
    long long count=0;
    void dfs(vector<vector<int>> &a,vector<int> &vis, int i){
        if(vis[i]==1)
        return;
        vis[i] = 1;
        count++;
        for(auto j : a[i])
        {
            if(vis[j]==0)
              dfs(a,vis,j);
        }
    }
    long long countPairs(int n, vector<vector<int>>& edges) {
        if(edges.size()==0)return (long long)n*(n-1)/2;

        vector<vector<int>> adj(n);
        for(int i=0;i<edges.size();i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            adj[edges[i][1]].push_back(edges[i][0]);
        }
        vector<int>vis(n,0);
        long long pre=0,ans=0;
        for(int i=0; i<n; i++){
            if(vis[i]==0){
                count=0;
                dfs(adj, vis, i);
                ans+=count*pre;
                pre+=count;
            }
        }
        return ans;
    }
};