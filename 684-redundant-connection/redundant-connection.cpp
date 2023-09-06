class DisjointSet{
public:
    vector<int>size, parent,rank;
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
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size();
        vector<int>adj[n+1];
        DisjointSet ds(n);
        vector<int>ans(2,0);
        for(auto i:edges){
            if(ds.findUParent(i[0])==ds.findUParent(i[1])){
                ans[0] = i[0];
                ans[1] = i[1];
            }
            else{
                ds.unionBySize(i[0],i[1]);
            }
        }
        return ans; 
    }
};