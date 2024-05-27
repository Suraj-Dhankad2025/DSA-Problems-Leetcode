class Solution {
public:
    bool possibleBipartition(int n, vector<vector<int>>& dislikes) {
        queue<int>q;
        vector<int>color(n+1, -1);
        
        vector<int>adj[n+1];
        for(auto i:dislikes){
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
        }
        for(int i=1; i<=n; i++){
            if(color[i]==-1){
                color[i] = 0;
                q.push(i);
                while(!q.empty()){
                    int node = q.front();
                    q.pop();
                    for(auto i:adj[node]){
                        if(color[i]==-1){
                            color[i] = (1+color[node])%2;
                            q.push(i);
                        }
                        else if(color[i]==color[node]){
                            return 0;
                        }
                    }
                }
            }
        }
        
        return 1;
    }
};