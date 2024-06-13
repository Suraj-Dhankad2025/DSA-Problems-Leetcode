class Solution {
public:
    vector<int> loudAndRich(vector<vector<int>>& richer, vector<int>& quiet) {
        int n = quiet.size();
        vector<int>topo, in(n, 0);
        vector<int>adj[n];
        for(int i=0; i<richer.size(); i++){
            adj[richer[i][0]].push_back(richer[i][1]);
            in[richer[i][1]]++;
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
            topo.push_back(node);
            for(auto i:adj[node]){
                in[i]--;
                if(in[i]==0){
                    q.push(i);
                }
            }
        }
        vector<int>ans(n, 0);
        for(int i=0; i<n; i++){
            ans[i] = i;
        }
        for(int i=0; i<n; i++){
            for(auto it:adj[topo[i]]){
                if(quiet[ans[it]]>quiet[ans[topo[i]]]){
                    ans[it] = ans[topo[i]];
                }
            }
        }
        return ans;
    }
};