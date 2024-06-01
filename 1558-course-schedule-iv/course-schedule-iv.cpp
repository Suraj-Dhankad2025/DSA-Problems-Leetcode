class Solution {
public:
    vector<bool> checkIfPrerequisite(int n, vector<vector<int>>& pre, vector<vector<int>>& queries) {
        vector<bool>ans(queries.size(), 0);
        vector<int>adj[n];
        vector<int>in(n, 0);
        vector<vector<bool>> reachable(n, vector<bool>(n, false));
        for(int i=0; i<pre.size(); i++){
            adj[pre[i][0]].push_back(pre[i][1]);
            reachable[pre[i][0]][pre[i][1]] = true;
            in[pre[i][1]]++;
        }
        queue<int>q;
        for(int i=0; i<n; i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto i:adj[node]){
                for(int k=0; k<n; k++){
                    if(reachable[k][node])reachable[k][i] = true;
                }
                in[i]--;
                if(in[i]==0){
                    q.push(i);
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
