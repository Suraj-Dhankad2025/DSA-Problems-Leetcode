class Solution {
public:
    int maxi=-1;
    void dfs(vector<int>adj[],vector<int>&vis,vector<int>&path, int node,int dis){
        vis[node]=1;
        path[node] = dis;
        for(auto it:adj[node]){
            if(vis[it]==0){
                dfs(adj,vis,path,it,dis+1);
            }
            else if(path[it]!=0){
                maxi=max(maxi,dis-path[it]+1);
            }
        }
        path[node]=0;
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>adj[n+1];
        for(int i=0;i<n;i++){
            if(edges[i]!=-1)
            adj[edges[i]].push_back(i);
        }
        vector<int>vis(n+1,0);
        vector<int>path(n+1,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(adj,vis,path,i,1);
            }
        }
        return maxi;
    }
};