class Solution {
public:
    void dfs(int node,int dis,vector<pair<int,int>>adj[],int &s,int &count,vector<int>&vis){
        if(dis%s==0) count++;
        vis[node]=1;
        for(auto it:adj[node]){
            if(!vis[it.first]){
                dfs(it.first,dis+it.second,adj,s,count,vis);
            }
        }
    }
    vector<int> countPairsOfConnectableServers(vector<vector<int>>& edges, int s) {
        int n=edges.size();
        vector<pair<int,int>>adj[n+1];
        for(auto it:edges){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        vector<int>ans(n+1,0);
        
        for(int i=0;i<=n;i++){
            vector<int>vis(n+1,0);
            vector<int>temp;
            for(auto it:adj[i]){
                vis[i]=1;
                int count=0;
                dfs(it.first,it.second,adj,s,count,vis);
                temp.push_back(count);
            }
            int sum=0;
            for(int k=0;k<temp.size();k++){
                for(int j=0;j<temp.size();j++){
                    if(k!=j){
                        sum+=temp[k]*temp[j];
                    }
                }
            }
            ans[i]=sum/2;
        }
        return ans;
    }
};