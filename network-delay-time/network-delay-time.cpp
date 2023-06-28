class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        if(times.size()<n-1)return -1;
        vector<int>vis(n,0);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
        vector<int>dist(n,1e9);
        dist[k-1]=0;
        vector<vector<int>>adj[n];
        for(int i=0;i<times.size();i++){
            int u=times[i][0]-1;
            int v=times[i][1]-1;
            int w=times[i][2];
            vector<int>vec;
            vec.push_back(v);
            vec.push_back(w);
            adj[u].push_back(vec);
        }
        pq.push({0,k-1});
        vis[k-1]=1;
        while(!pq.empty()){
            int d=pq.top().first;
            int node=pq.top().second;
            vis[node]=1;
            pq.pop();
            for(auto it:adj[node]){
                int edw=it[1];
                int adjNode=it[0];
                if(d+edw<dist[adjNode]){
                    dist[adjNode]=d+edw;
                    pq.push({dist[adjNode],adjNode});
                }
            }
        }
        int res=dist[0];
        for(int i=0;i<n;i++){
            res=max(res,dist[i]);
            if(!vis[i])return -1;
        }
        return res;
    }

    //     if(edges.size()<n-1)return -1;
    //     vector<int>time(n,1e9);
    //     set<pair<int, int>>s;
       
    //     s.insert({0,k-1});
    //     time[k-1] = 0;
    //     vector<vector<int, int>>adj[n];
    //     for(int i=0; i<edges.size(); i++){
    //         int u = edges[i][0]-1;
    //         int v = edges[i][1]-1;
    //         int w = edges[i][2];
    //         vector<int>vec;
    //         vec.push_back(v);
    //         vec.push_back(w);
    //         adj[u].push_back(vec);
    //     }

    //     while(!s.empty()){
    //         auto it = *s.begin();
    //         int t = it.first;
    //         int node = it.second;
    //         s.erase(it);
    //         for(auto i:adj[node]){
    //             int adjNode = i[0];
    //             int wt = i[1];
    //             if(t + wt < time[adjNode]){
    //                 if(time[adjNode]!=1e9){
    //                     s.erase({time[adjNode], adjNode});
    //                 }
    //                 time[adjNode] = t + wt;
    //                 s.insert({time[adjNode], adjNode});
    //             }
    //         } 
    //     }
    //     int ans=time[0];
    //     for(int i=0;i<n;i++){
    //         ans = max(ans, time[i]);
    //         if(time[i]==1e9){
    //             return -1;
    //         }
    //     }
    //     return ans;
    // }
};