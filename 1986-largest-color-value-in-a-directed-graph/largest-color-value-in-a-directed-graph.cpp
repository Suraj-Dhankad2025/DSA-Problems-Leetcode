class Solution {
public:
    int dfs(int node, vector<int>&vis, vector<int>&path, vector<int>adj[]){
        vis[node] = 1;
        path[node] = 1;
        for(auto i:adj[node]){
            if(!vis[i] && dfs(i, vis, path, adj)){
                return -1;
            }
            else if(path[i]){
                return -1;
            }
        }
        path[node] = 0;
        return 0;
    }
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        int n = colors.size();
        vector<int>in(n, 0);
        vector<int>adj[n];
        for(int i=0; i<edges.size(); i++){
            adj[edges[i][0]].push_back(edges[i][1]);
            in[edges[i][1]]++;
        }
        vector<vector<int>>count(n, vector<int>(26, 0));
        queue<int>q;
        for(int i=0; i<n; i++){
            if(in[i]==0){
                q.push(i);
                count[i][colors[i]-'a']++;
            }
        }
        vector<int>vis(n, 0);
        vector<int>path(n, 0);
        int ans = -2;
        for(int i=0; i<n; i++){
            if(!vis[i]){
                if(dfs(i, vis, path, adj)==-1){
                    return -1;
                }
            }
        }
        while(!q.empty()){
            int node = q.front();
            q.pop();
            int way = *max_element(count[node].begin(), count[node].end());
            ans = max(ans, way);
            for(auto neighbour:adj[node]){
                for(int i=0; i<26; i++){
                    count[neighbour][i] = max(count[neighbour][i], count[node][i]+(i==colors[neighbour]-'a'));
                }
                in[neighbour]--;
                if(in[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
        return ans;
    }
};