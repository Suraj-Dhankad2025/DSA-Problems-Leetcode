class DisjointSet{
    public:
    vector<int>size,parent;
    DisjointSet(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0; i<=n; i++){
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findUParent(int u){
        if(u==parent[u]){
            return u;
        }
        return parent[u] = findUParent(parent[u]);
    }
    void unionBySize(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if(ulp_u==ulp_v){
            return ;
        }
        if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};
class Solution {
public:
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int row = 0;
        int col = 0;
        for(auto i:stones){
            row = max(row, i[0]);
            col = max(col, i[1]);
        }
        DisjointSet ds(row+col+1);
        unordered_map<int, int>m;
        for(auto i:stones){
            int nodeRow = i[0];
            int nodeCol = i[1] + 1 + row;
            ds.unionBySize(nodeRow, nodeCol);
            m[nodeRow] = 1;
            m[nodeCol] = 1;
        }
        int c=0;
        for(auto i:m){
            if(ds.findUParent(i.first)==i.first){
                c++;
            }
        }
        return n-c;
    }
};