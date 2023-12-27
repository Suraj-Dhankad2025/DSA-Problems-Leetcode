// class Solution {
// public:
//     vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& red, vector<vector<int>>& blue) {
//         vector<pair<int,char>>adj[n];
//         for(auto it:red){
//             adj[it[0]].push_back({it[1],'R'});
//         }
//         for(auto it:blue){
//             adj[it[0]].push_back({it[1],'B'});
//         }

//         vector<int>ans(n,INT_MAX);
//         priority_queue<pair<int,pair<int,char>>,vector<pair<int,pair<int,char>>>,greater<pair<int,pair<int,char>>>>pq;
//         pq.push({0,{0,'B'}});
//         pq.push({0,{0,'R'}});
//         ans[0]=0;
//         unordered_map<int,char>mp;
//         while(!pq.empty()){
//             int node=pq.top().first;
//             char col=pq.top().second.second;
//             int dis=pq.top().second.first;
//             pq.pop();
//             if(mp[node]==col){
//                 continue;
//             }
//             else{
//                 mp[node]=col;
//             }
//             for(auto it:adj[node]){
//                 pair<int,char>p=it;
//                 if(col!=p.second){
//                     pq.push({p.first,{dis+1,p.second}});
//                     if(ans[p.first]>dis+1)ans[p.first]=dis+1;
//                 }
//             }
//         }
//         for(int i=0;i<n;i++){
//             if(ans[i]==INT_MAX){
//                 ans[i]=-1;
//             }
//         }
//         return ans;
//     }
// };
class Solution {
public:
    void bfs(int n,vector<pair<int,int>> adj[],vector<int> &dp){
        queue<vector<int>> q;
        q.push({0,0,0});
        q.push({0,0,1});
        vector<vector<int>> vis(n,vector<int>(2,0));
        vis[0][0]=1;
        vis[0][1]=1;
        while(!q.empty()){
            auto curr=q.front();q.pop();
            int d=curr[0],node=curr[1],c1=curr[2];
            for(auto x:adj[node]){
                int child=x.first,c2=x.second;
                if(c2!=c1){
                    dp[child]=min(dp[child],1+d);
                    if(vis[child][c2]==0) q.push({1+d,child,c2});
                    vis[child][c2]=1;
                }
            }
        }
    }
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& R, vector<vector<int>>& B) {
        vector<pair<int,int>> adj[n];
        for(auto x:R){
            adj[x[0]].push_back({x[1],1});
        }
        for(auto x:B){
            adj[x[0]].push_back({x[1],0});
        }
        vector<int> dp(n,INT_MAX-1);
        dp[0]=0;
        bfs(n,adj,dp);
        for(int i=0;i<n;i++){
            if(dp[i]>=INT_MAX-1) dp[i]=-1;
        }
        return dp;
    }
};