class Solution {
public:
 void solve(int node,vector<int>&path,vector<int>&vis,vector<int>adj[],int temp,int &ans)
    {
        vis[node]=1;
        path[node]=temp;
        for(auto it:adj[node])
        {
            if(vis[it]==0) solve(it,path,vis,adj,temp+1,ans);
            else if(path[it]!=0) ans=max(ans,temp-path[it]+1);
        }
        path[node]=0;
    }
    int longestCycle(vector<int>& edges) {
        int n=edges.size();
        vector<int>adj[n];
        for(int i=0;i<n;i++)
        {
            if(edges[i]!=-1)
                adj[i].push_back(edges[i]);
        }
        vector<int>vis(n,0);
        vector<int>path(n,0);
        int ans=0;
        for(int i=0;i<n;i++)
        {
            if(!vis[i])
            {
                solve(i,path,vis,adj,1,ans);
            }
        }
        if(ans==0) return -1;
        return ans;
    }
};