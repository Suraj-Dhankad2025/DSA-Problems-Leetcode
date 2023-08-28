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
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size();
        DisjointSet ds(n*n);
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                if(grid[r][c]==0) continue;
                int dr[4] = {1, 0, -1, 0};
                int dc[4] = {0, 1, 0, -1};
                for(int ind=0; ind<4; ind++){
                    int nr = r + dr[ind];
                    int nc = c + dc[ind];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        int node = r*n + c;
                        int adjNode = nr*n + nc;
                        ds.unionBySize(node, adjNode);
                    }
                }
            }
        }
        int ans=0;
        for(int r=0; r<n; r++){
            for(int c=0; c<n; c++){
                if(grid[r][c]==1) continue;
                int dr[4] = {1, 0, -1, 0};
                int dc[4] = {0, 1, 0, -1};
                set<int>s;
                for(int ind=0; ind<4; ind++){
                    int nr = r + dr[ind];
                    int nc = c + dc[ind];
                    if(nr>=0 && nr<n && nc>=0 && nc<n && grid[nr][nc]==1){
                        s.insert(ds.findUParent(nr*n + nc));
                    }
                }
                int size=0;
                for(auto it:s){
                    size+=ds.size[it];
                }
                ans = max(ans, size+1);
            }
        }
        for(int i=0; i<n*n; i++){
             ans = max(ans, ds.size[ds.findUParent(i)]);
        }
        return ans;
    }
};