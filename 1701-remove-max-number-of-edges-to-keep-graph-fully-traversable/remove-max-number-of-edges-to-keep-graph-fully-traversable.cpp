class DisjointSet{
    private:
        vector<int>size,parent;
    public:
        DisjointSet(int n){
            size.resize(n+1, 1);
            parent.resize(n+1);
            for(int i=0; i<=n; i++){
                parent[i] = i;
            }
        }
        int findUParent(int node){
            if(node==parent[node]){
                return node;
            }
            return parent[node] = findUParent(parent[node]);
        }
        bool unionBySize(int u, int v){
            int ulp_u = findUParent(u);
            int ulp_v = findUParent(v);
            if(ulp_u==ulp_v){
                return false;
            }
            if(size[ulp_v]>size[ulp_u]){
                parent[ulp_u] = ulp_v;
                size[ulp_v]+=size[ulp_u];
            }
            else{
                parent[ulp_v] = ulp_u;
                size[ulp_u]+=size[ulp_v];
            }
            return true;
        }
};
class Solution {
public:
    int maxNumEdgesToRemove(int n, vector<vector<int>>& edges) {
        DisjointSet bob(n);
        DisjointSet alice(n);

        int removedEdges = 0;
        int aliceEdges = 0, bobEdges = 0;
        for(auto it:edges){
            int type = it[0];
            int u = it[1];
            int v = it[2];
            if(type == 3){
                bool aliceEdge = alice.unionBySize(u,v);
                bool bobEdge = bob.unionBySize(u,v);
                if(!aliceEdge && !bobEdge){
                    removedEdges++;
                }
                else{
                    if(aliceEdge) aliceEdges++;
                    if(bobEdge) bobEdges++;
                }
            }
        }
        for(auto it:edges){
            int type = it[0];
            int u = it[1];
            int v = it[2];
            if(type == 1){
                bool aliceEdge = alice.unionBySize(u,v);
                if(aliceEdge) aliceEdges++;
                else{
                    removedEdges++;
                }
            }
            
        }
        for(auto it:edges){
            int type = it[0];
            int u = it[1];
            int v = it[2];
            if(type == 2){
                bool bobEdge = bob.unionBySize(u,v);
                if(bobEdge) bobEdges++;
                else{
                    removedEdges++;
                }
            }
        }
        if(aliceEdges==n-1 && bobEdges==n-1){
            return removedEdges;
        }
        return -1;
    }
};