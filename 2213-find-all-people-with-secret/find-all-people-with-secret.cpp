class Solution {
public:
    vector<int> findAllPeople(int n, vector<vector<int>>& meetings, int firstPerson) {
        vector<pair<int, int>>adj[n];
        for(auto i:meetings){
            adj[i[0]].push_back({i[1], i[2]});
            adj[i[1]].push_back({i[0], i[2]});
        }
        queue<pair<int, int>>q;
        q.push({0, 0});
        q.push({0, firstPerson});

        vector<int>dis(n, INT_MAX);
        dis[0] = 0;
        dis[firstPerson] = 0;

        while(!q.empty()){
            auto [time, node] = q.front();
            q.pop();
            for(auto [newNode, newTime]:adj[node]){
                if(time <= newTime && newTime<dis[newNode]){
                    dis[newNode] = newTime;
                    q.push({newTime, newNode});
                }
            }
        }
        vector<int>ans;
        for(int i=0; i<n; i++){
            if(dis[i]!=INT_MAX){
                ans.push_back(i);
            }
        }
        return ans;
    }
};