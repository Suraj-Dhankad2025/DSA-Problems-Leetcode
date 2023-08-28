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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        unordered_map<string, int>m;
        DisjointSet ds(n);
        for(int i=0;i<n;i++){
            for(int j=1; j<accounts[i].size(); j++){
                string s = accounts[i][j];
                if(m.find(s)==m.end()){
                    m[s] = i;
                }
                else{
                    ds.unionBySize(i,m[s]);
                }
            }
        }
        vector<string>merged[n];
        for(auto i:m){
            string mail = i.first;
            int node = ds.findUParent(i.second);
            merged[node].push_back(mail);
        }
        vector<vector<string>>ans;
        for(int i=0; i<n; i++){
            if(merged[i].size()==0)continue;
            sort(merged[i].begin(), merged[i].end());
            vector<string>temp;
            temp.push_back(accounts[i][0]);
            for(auto it:merged[i]){
                temp.push_back(it);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};