class DisjointSet{
    vector<int>size, parent,rank;
public:
    DisjointSet(int n){
        size.resize(n+1);
        parent.resize(n+1);
        rank.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
            size[i] = i;
        }
    }
    int findUParent(int node){
        if(node==parent[node]){
            return node;
        }
        return parent[node] = findUParent(parent[node]);
    }
    void unionByRank(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if(ulp_u==ulp_v){
            return ;
        }
        if(rank[ulp_v]>rank[ulp_u]){
            parent[ulp_u] = ulp_v;
        }
        else if(rank[ulp_v]<rank[ulp_u]){
            parent[ulp_v] = ulp_u;
        }
        else{
            parent[ulp_v] = ulp_u;
            rank[ulp_u]++;
        }
    }
    void unionBySize(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if(ulp_u==ulp_v){
            return ;
        }
        if(size[ulp_v]>size[ulp_u]){
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
        else{
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
    }
};
class Solution {
public:
    int find(vector<int>&v1 , vector<int>&v2){
        return abs(abs(v1[0]-v2[0]) + abs(v1[1]-v2[1]));
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
         int n = points.size();
         vector<pair<int,int>>adj[n];
         for(int i=0; i<n ; i++){
            for(int j=i+1;j<n ; j++){
                adj[i].push_back({j,find(points[i],points[j])});
                adj[j].push_back({i,find(points[i],points[j])});
            }
        }
        vector<pair<int, pair<int,int>>>edges;
        for(int i=0; i<n; i++){
            for(auto it:adj[i]){
                int node = i;
                int adjNode = it.first;
                int wt = it.second;
                edges.push_back({wt, {node, adjNode}});
            }
        }
        sort(edges.begin(), edges.end());
        DisjointSet ds(n);
        int sum=0;
        for(auto it:edges){
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(ds.findUParent(u)!=ds.findUParent(v)){
                sum+=wt;
                ds.unionBySize(u,v);
            }
        }
        return sum;
    //      priority_queue<pair<int, int> , vector<pair<int, int>>, greater<pair<int, int>>>pq;
      
    //    vector<int>vis(n,0);
    //    pq.push({0,0});
    //    int sum = 0;
    //    while(!pq.empty()){
    //        int node = pq.top().second;
    //        int wt = pq.top().first;
    //        pq.pop();
    //        if(vis[node]==1)continue;
    //        vis[node] = 1;
    //        sum+=wt;
    //        for(auto i:adj[node]){
    //            int adjNode = i.first;
    //            int edgeWt = i.second;
    //            if(!vis[adjNode]){
    //                pq.push({edgeWt, adjNode});
    //            }
    //        }
    //    }
    //    return sum;
    }
};