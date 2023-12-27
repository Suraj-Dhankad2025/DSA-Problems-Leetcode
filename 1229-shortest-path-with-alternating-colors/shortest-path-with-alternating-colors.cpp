class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<pair<int, char>>adj[n];
        for(auto i:redEdges){
            adj[i[0]].push_back({i[1],'R'});
        }
        for(auto i:blueEdges){
            adj[i[0]].push_back({i[1],'B'});
        }
        vector<int>ans(n, INT_MAX);
        queue<pair<int, pair<int, char>>>q;
        q.push({0, {0, 'R'}});
        q.push({0, {0, 'B'}});
        map<pair<int, char>, int>m;
        m[{0,'R'}] = 1;
        m[{0,'B'}] = 1;
        ans[0] = 0;
        while(!q.empty()){
            int node = q.front().first;
            int dis = q.front().second.first;
            char color = q.front().second.second;
            q.pop();
            for(auto i:adj[node]){
                int newNode = i.first;
                char newColor = i.second;
                if(color!=newColor){
                    if(m.find({newNode, newColor})==m.end()){
                        q.push({newNode, {dis+1,newColor}});
                    }
                    ans[newNode] = min(ans[newNode], 1+dis);
                    m[{newNode, newColor}] = 1;
                }
            }
        }
        for(int i=0; i<n; i++){
            if(ans[i]==INT_MAX){
                ans[i] = -1;
            }
        }
        return ans;
    }
};