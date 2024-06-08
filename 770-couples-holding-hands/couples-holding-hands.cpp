class DisjointSet{
public:
    vector<int>size, parent;
    DisjointSet(int n){
        size.resize(n+1);
        parent.resize(n+1);
        for(int i=0; i<n+1; i++){
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
    void unionBySize(int u, int v){
        int ulp_u = findUParent(u);
        int ulp_v = findUParent(v);
        if(ulp_u==ulp_v){
            return;
        }
        if(size[ulp_u]>size[ulp_v]){
            parent[ulp_v] = ulp_u;
            size[ulp_u]+=size[ulp_v];
        }
        else{
            parent[ulp_u] = ulp_v;
            size[ulp_v]+=size[ulp_u];
        }
    }
};
class Solution {
public:
    int minSwapsCouples(vector<int>& row) {
        int n = row.size();
        DisjointSet ds(n);
        for(int i=1; i<n; i+=2){
            int u = row[i-1];
            int v = row[i];
            ds.unionBySize(u,v);
        }
        int c = 0;
        for(int i=1; i<n; i+=2){
            if(ds.findUParent(i-1)!=ds.findUParent(i)){
                ds.unionBySize(i, i-1);
                c++;
            }
        }
        return c;
    }
};