class Solution {
public:
    int minimumTime(int n, vector<vector<int>>& relations, vector<int>& time) {
        vector<int>adj[n];
        for(int i=0; i<relations.size(); i++){
            adj[relations[i][0]-1].push_back(relations[i][1]-1);
        }
        vector<int>in(n, 0);
        for(int i=0; i<n; i++){
            for(auto j:adj[i]){
                in[j]++;
            }
        }
        queue<int>q;
        for(int i=0; i<n; i++){
            if(in[i]==0){
                q.push(i);
            }
        }
        vector<int>prevTime(n, 0);
        while(!q.empty()){
            int node = q.front();
            q.pop();
            for(auto i:adj[node]){
                in[i]--;
                if(in[i]==0){
                    q.push(i);
                }
                prevTime[i] = max(prevTime[i], time[node]+prevTime[node]);
            }
        }
        int ans = 0;
        for(int i=0; i<prevTime.size(); i++){
            ans = max(ans, prevTime[i]+time[i]);
        }
        return ans;
    }
};