class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        int n = pairs.size();
        map<int, vector<int>>adj;
        map<int, int>outdeg;
        for(int i=0; i<pairs.size(); i++){
            int u = pairs[i][0];
            int v = pairs[i][1];
            adj[u].push_back(v);
            outdeg[u]++;
            outdeg[v]--;
        }
        int start = pairs[0][0];
        for(auto i:outdeg){
            if(i.second == 1){
                start = i.first;
                break;
            }
        }
        stack<int> stk;
        vector<int> path;
        stk.push(start);
        
        while (!stk.empty()) {
            int node = stk.top();
            if (adj[node].empty()) {
                path.push_back(node);
                stk.pop();
            } else {
                int next_node = adj[node].back();
                adj[node].pop_back();
                stk.push(next_node);
            }
        }
        reverse(path.begin(), path.end());
        vector<vector<int>> ans;
        for (int i = 1; i < path.size(); ++i) {
            ans.push_back({path[i-1], path[i]});
        }
        return ans;
    }
};