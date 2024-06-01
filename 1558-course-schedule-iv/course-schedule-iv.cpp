class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<bool>ans(queries.size(), 0);
        vector<int>adj[n];
        vector<int>in(n, 0);
        for(int i=0; i<pre.size(); i++){
            adj[pre[i][0]].push_back(pre[i][1]);
            in[pre[i][1]]++;
        }
        queue<int>q;
        for(int i=0; i<n; i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        vector<int>topo;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            topo.push_back(node);
            for(auto i:adj[node]){
                in[i]--;
                if(in[i]==0){
                    q.push(i);
                }
            }
        }
        vector<vector<bool>> reachable(n, vector<bool>(n, false));
        for (int i = 0; i < n; ++i) {
            reachable[i][i] = true;
        }
        for (const auto& p : pre) {
            reachable[p[0]][p[1]] = true;
        }
        for (int k = 0; k < n; ++k) {
            for (int i = 0; i < n; ++i) {
                for (int j = 0; j < n; ++j) {
                    if (reachable[i][k] && reachable[k][j]) {
                        reachable[i][j] = true;
                    }
                }
            }
        }
        for (int i = 0; i < queries.size(); ++i) {
            int u = queries[i][0];
            int v = queries[i][1];
            ans[i] = reachable[u][v];
        }
        return ans;
    }
};
